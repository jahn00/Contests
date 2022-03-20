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
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

signed main() {
    fastio;
    int n; int x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp (n, vector<int>(10000 + 1, -1));

    function<int(int, int)> f = [&](int i, int pos) {
        //cout << "idx: " << i << ", pos: " << pos << endl;
        if (i == n) {
            return pos == x ? 1 : 0;
        }
        if (pos > x) return 0;
        int& res = dp[i][pos];
        if (~res) return res;
        res = f(i + 1, pos + a[i]) || f(i + 1, pos + b[i]);
        return res;
    };

    int res = f(0, 0);
    if (res == 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}