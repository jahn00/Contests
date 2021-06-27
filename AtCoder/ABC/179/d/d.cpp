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

const int md = 998244353; 
const int mn = 2e5 + 10;
int dp[mn];
int n;

int f(const vector<int>&a, int idx) {
    if (idx == n) {return 1;}
    int& res = dp[idx];
    if (~res) return res;

    res = (0);
    for (int i = 0; i < a.size(); i++) {
        int d = a[i];
        if (idx + d > n) break;
        res += f(a, idx + d);
        if (res >= md) res -= md;
    }
    return res;
}

signed main() {
    fastio;
    int k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    rep (i,k) {
        int l , r; cin >> l >> r;
        for (; l<=r; l++) mp[l]++;
    }
    vector<int> a;
    for (auto p : mp)  {
        a.push_back(p.first);
    }

    memset(dp, -1, sizeof dp);
    cout << f(a, 1) << endl;
}