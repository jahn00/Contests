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

const int md = 998244353, mn = 3010;
int n, s;
int f[mn][mn];
int a[mn];

signed main() {
    fastio;
    cin >> n >> s;
    memset(f, 0, sizeof f);
    rep (i, n) {
      int ai;
      cin >> ai;
      a[i] = ai;
    }

    int res = 0;
    rep (i, n) {
      rep (j, s + 1) {
        int& ff = f[i+1][j];
        ff += f[i][j];
        if (j - a[i] > 0)
          ff += f[i][j - a[i]];
        else if (j - a[i] == 0) 
          ff += i + 1;
        ff %= md;
      }
      res += (f[i + 1][s] * (n - i)) % md;
      res %= md;
      f[i + 1][s] = 0;
    }
    cout << res << endl;
}