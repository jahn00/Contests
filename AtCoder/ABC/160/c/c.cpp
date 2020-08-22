#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }
const int maxn = 2e5 + 1;
int a[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> ccw(n + 1, 0);
  for (int i = n-1; i >= 0; i--) {
    ccw[i] = k - a[i];
  }
  int res = a[n-1] - a[0];
  for (int i = 0; i + 1 < n; i++){
    res = min(res, a[i] + ccw[i + 1]);
  }
  cout << res << endl;

}
