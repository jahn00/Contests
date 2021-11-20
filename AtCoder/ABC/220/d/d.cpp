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

int n;
const int mxn = 1e5, md = 998244353;
int a[mxn + 4];
vector<vector<int>> dp;

int K;

int f(int idx, int k) {
    if (idx == n) {
        return k == K;
    }
    int& res = dp[idx][k];
    if (~res) return res;
    res = 0;

    res += (f(idx + 1, (k + a[idx]) % 10) + f(idx + 1, (k * a[idx]) % 10)) % md;
    res %= md;
    return res;
}

signed main() {
    fastio;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, 10) {
        K = i;
        dp.assign(n + 1, vector<int>(10, -1));
        cout << f(1, a[0]) << endl;
    }
}
