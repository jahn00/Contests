#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }
const int maxn = 2e5;
int dp[10][10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    int l = i % 10;
    int h = i;
    int hh = i/ 10;
    while (hh) { h /= 10; hh /= 10; }
    dp[l][h]++;
  }
  ll res = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      res += dp[i][j] * dp[j][i];
  Out(res);
}
