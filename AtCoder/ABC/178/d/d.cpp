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

const int mn = 2010;
int S;
int dp[mn];
const int md = 1e9 + 7;

int f(int sum) {
    if (sum > S) return 0;
    if (sum == S) {
        return 1;
    }
    int& res = dp[sum];
    if (~res) return res;
    res = 0;
    for (int i = 3; i <= S - sum; i++) {
        res += f(sum + i);
        if (res >= md) res -= md;
    }
    return res;
}

signed main() {
    fastio;
    cin >> S;

    memset(dp, -1, sizeof dp);
    int res = f(0);
    
    cout << res << endl;
    return 0;
}