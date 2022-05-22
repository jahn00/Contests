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
    vector<vector<int>> a(10); // int -> [idx]
    rep(_, n) {
        string s; cin >> s;
        rep (i, 10) {
            a[s[i] - '0'].push_back(i);
        }
    }
    int res = 1e9;
    for (auto& x : a) {
        sort(all(x));
        set<int> visited_times;
        for (auto& idx : x) {
            while (visited_times.count(idx)) {
                idx += 10;
            }
            visited_times.emplace(idx);
        }
        sort(all(x));
        res = min(x.back(), res);
    }
    cout << res << endl;
}