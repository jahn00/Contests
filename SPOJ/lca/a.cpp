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
    int u; // vertex
    int d; // depth
    node() {
        this-> u = 0; this->d = inf;
    }
    node (int i, int d) {
        this->u = i; this->d = d;
    }

    bool operator<(const node& rhs) const {
        return this->d < rhs.d;
    }
};

node min(const node& lhs, const node& rhs) {
    return (lhs < rhs) ? lhs : rhs;
}

struct Segtree {
    // rmq segtree
    int n;
    vector<node> seg;

    Segtree() {
        this->n = euler.size();
        seg.resize(2 * n + 1);
        for (int i = 0; i < n; i++) {
            seg[i + n] = node(euler[i], depth[euler[i]]);
        }

        // build RMQ tree
        for (int i = n-1; i > 0; i--) {
            seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    int lca(int u, int v) {
        // transform vertices to indices in euler array
        int l = first[u]; int r = first[v];
        if (l > r) swap(l, r);
        r++;
        node res = get(l, r);
        /*
        cout << "vertices: (" << u << ", " << v << ")" << endl;
        cout << "idx in euler array: [" << l << ", " << r << ")" << endl;
        cout << "lca vertex: " << res.u << " depth: " << res.d << endl;
        */
        return res.u;
    }

    node get(int l, int r) {
        l += n; r += n;
        node resl = seg[l];
        node resr = seg[r];
        for (; l < r; l >>= 1, r >>= 1) {
            if (l % 2) { 
                resl = min(seg[l++], resl);
            }
            if (r % 2) {
                resr = min(seg[--r], resr);
            }
        }
        return min(resl, resr);
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

void solve() {
    cin >> N;
    g.assign(N, vector<int>());
    rep(i, N) {
        // for each vertex i, we have m neighbors
        int m; cin >> m;
        rep(j, m) {
            int v; cin >> v; v--;
            g[i].push_back(v);
        }
    }

    first.assign(N, 0); // vertex u -> idx of its first occurrence in euler array
    depth.assign(N, 0); // vertex u -> depth of vertex u
    euler.clear(); // i -> u, the ith vertex in the euler tour
    visit.assign(N, 0); // u -> 1 if visited, 0 o.w.
    dfs(0, 0); // dfs(u, h) rooted at u, height h

    Segtree seg;

    int _q;
    cin >> _q;
    rep(_, _q) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u == v) cout << u + 1 << endl;
        else cout << seg.lca(u, v) + 1 << endl;
    }
}

signed main() {
    fastio;
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ":" << endl;
        solve();
    }
}