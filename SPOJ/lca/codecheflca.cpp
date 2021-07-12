#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>
#include <bitset>
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

vector<vector<int>> g;
int N, Q;

vector<int> first, euler, depth, visit;

// euler: i -> vertex u in euler tour
struct node {
    int u, d;
    node() {
        this-> u = 0; this->d = 0;
    }
    node (int i, int d) {
        this->u = i; this->d = d;
    }

    bool operator<(node& rhs) const {
        return this->d < rhs.d;
    }
};

struct Segtree {
    // rmq segtree
    int n;
    vector<node> seg;

    Segtree() {
        this->n = euler.size();
        seg.resize(2 * n);
        for (int i = 0; i < n; i++) {
            seg[i + n] = node(euler[i], depth[euler[i]]);
        }

        // build RMQ tree
        for (int i = n-1; i > 0; i--) {
            seg[i] = (seg[i << 1] < seg[i << 1 | 1]) ? seg[i << 1] : seg[i << 1 | 1];
        }
    }

    int lca(int u, int v) {
        // transform vertices to indices in euler array
        int l = first[u]; int r = first[v];
        if (l > r) swap(l, r);
        node res = get(l, r);
        /*
        cout << "vertices: (" << u << ", " << v << ")" << endl;
        cout << "idx in euler array: [" << l << ", " << r << ")" << endl;
        cout << "lca vertex: " << res.u << " depth: " << res.d << endl;
        */
        return res.u;
    }

    node get(int l, int r) {
        l += n; r += n + 1;
        node mini = seg[l] < seg[r] ? seg[l] : seg[r];
        for (; l < r; l >>= 1, r >>= 1) {
            if (l % 2) { 
                if (seg[l] < mini) {
                    mini = seg[l]; l++;
                }
            }
            if (r % 2) {
                if (seg[--r] < mini) {
                    mini = seg[r];
                }
            }
        }
        return mini;
    }
};

void dfs(int u, int h) {
    visit[u] = 1;
    depth[u] = h;
    first[u] = euler.size(); // derp
    euler.push_back(u);

    for (auto& v : g[u]) {
        if (visit[v]) continue;
        dfs(v, h + 1);
        euler.push_back(u);
    }
}

signed main() {
    fastio;
    int N; cin >> N; 
    g.assign(N, vector<int>());
    rep(i, N-1) {
        // for each edge, we have 2 vertices u, v
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    first.assign(N, 0); // vertex u -> idx of its first occurrence in euler array
    depth.assign(N, 0); // vertex u -> depth of vertex u
    euler.clear(); // i -> u, the ith vertex in the euler tour
    visit.assign(N, 0); // u -> 1 if visited, 0 o.w.
    dfs(0, 0); // dfs(u, h) rooted at u, height h

    Segtree seg;

    int _q;
    cin >> _q;
    vector<pair<int, int>> Q(_q);
    for (auto& q : Q) {
        cin >> q.first >> q.second;
        q.first--; q.second--;
    }
    for (auto& q : Q) {
        if (q.first == q.second) {
            cout << q.first + 1 << endl;
        }
        else cout << seg.lca(q.first, q.second) + 1 << endl;
    }
}