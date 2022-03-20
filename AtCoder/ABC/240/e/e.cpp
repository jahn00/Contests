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
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;

signed main() {
    fastio;
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<int,int>> intervals(n + 1, {-inf, -inf});  // vertex -> interval
    // assign intervals to each
    int counter = 1;
    function<void(int, int)> f = [&](int u, int parent) {
        if (g[u].size() == 1 and g[u][0] == parent) {
            // leaves have no other neighs besides parent
            intervals[u] = {counter, counter};
            counter++;
            return;
        }

        for (auto& v : g[u]) {
            if (v == parent) continue;
            f(v, u);
        }
    };
    f(1, -1);
    function<pair<int,int> (int, int)> dfs = [&](int u, int parent) {
        if (intervals[u].first != -inf) {
            return intervals[u];
        }
        int l = inf, r = -inf;
        for (auto& v : g[u]) {
            if (v == parent) continue;
            auto p = dfs(v, u);
            l = min(l, p.first);
            r = max(r, p.second);
        }
        return intervals[u] = {l, r};
    };
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        auto p = intervals[i];
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}