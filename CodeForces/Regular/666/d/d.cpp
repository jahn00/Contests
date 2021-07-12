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
#define endl '\n'
using namespace std;
const int inf = 0x3f3f3f3f;
const int mn = 102;
int n;
int dp[mn][2];
int pi[mn];

int f(int idx, int maxp) {
    int& res = dp[idx][maxp];
    if (~res) return res;
    res = maxp ? -inf : inf;
    for (int i = 0; i < n; i++) {
        if (pi[i] == 0 || i == idx) continue;
        pi[i] -= 1;
        if (maxp) 
            res = max(res, 1 + f(i, 0));
        else 
            res = min(res, -1 + f(i, 1));
        pi[i] += 1;
    }
    return res;
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        cin >> n;
        rep (i, n) {
            int ai;
            cin >> ai;
            pi[i] = ai;
        }

        memset(dp, -1, sizeof dp);
        int res = -inf;
        rep (i, n) {
            res = max(res, 1 + f(i, 0));
        }
        cout << "res for T: " << res;
        if (res < 0) {
            cout << "HL" << endl;
        } else {
            cout << "T" << endl;
        }
    }
}