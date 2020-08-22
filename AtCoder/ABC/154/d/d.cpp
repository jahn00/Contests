#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
double prob[maxn];
double pre[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  double p;
  pre[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> p;
    prob[i] = (1.0*p*(p+1)/2)/p;
    pre[i + 1] = pre[i] + prob[i];
    // cout << prob[i] << endl;
  }
  double res = -1;
  for (int i = 0; i + k <= n; i++) {
    res = max(res, (pre[i+k] - pre[i]));
  }
  cout << setprecision(6) << fixed << res << endl;
}
