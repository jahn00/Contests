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
#define pb emplace
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
signed main() {
    fastio;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, 0)), h(n, vector<int>(n, 0));
    rep(i, m) {
        int u, v;
        cin >> u >> v; u--; v--;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    rep(i, m) {
        int u, v;
        cin >> u >> v; u--; v--;
        h[u][v] = 1;
        h[v][u] = 1;
    }
    vector<int> pi(n);
    iota(all(pi), 0);
    do {
        bool found = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                found &= h[i][j] == g[pi[i]][pi[j]];
            }
        }

        if (found) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(all(pi)));
    cout << "No" << endl;
    return 0;
}