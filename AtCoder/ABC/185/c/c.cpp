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

const int mn = 210, cuts = 13;
int f[mn][cuts];

int len;

int go(int idx, int rem) {
    if (rem < 0) return 0;
    if (rem == 0) return 1;
    if (idx == len) {
        return rem == 0;
    }
    int& res = f[idx][rem];
    if (~res) return res;
    res = 0;
    res += go(idx + 1, rem) + go(idx + 1, rem - 1);
    return res;
}

signed main() {
    fastio;
    cin >> len;
    memset(f, -1, sizeof f);
    int res = go(1, 11);
    cout << res << endl;
    return 0;
}