#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>
#define print(x) cout << (#x) << " is " << (x) << endl;
#define printstd(x)                                                           \
    for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
    cout << endl;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visit;

signed main() {
    fastio;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    vector<int> deg(n + 1, 0);
    set<pair<int,int>> st;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        auto p = make_pair(u, v);
        // skip the dupes
        if (st.count(p)) continue;
        if (st.count({v, u})) {
            // not acyclic
            cout << -1 << endl;
            return 0;
        }
        g[u].push_back(v);
        deg[v]++;
        st.insert(p);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    visit.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) if (deg[i] == 0) {
        pq.emplace(i);
    }
    vector<int> res;
    while (pq.size()) {
        auto top = pq.top(); pq.pop();
        res.emplace_back(top);
        for (auto& v : g[top]) {
            deg[v]--;
            if (deg[v] == 0) {
                pq.emplace(v);
            }
        }
    }
    if (res.size() < n) { cout << -1 << endl; return 0; }
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}