#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

const int maxh = 1e4 + 10;
const int maxn = 1e3 + 10;
int dp[maxh];
int a[maxn], b[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int H, n;
  cin >> H >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j <= H; j++) {
      int h = min(j + a[i], H);
      dp[h] = min(dp[h], dp[j] + b[i]);
    }
  }
  Out(dp[H]);
}
