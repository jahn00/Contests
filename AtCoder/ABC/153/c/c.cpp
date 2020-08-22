#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int h[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(h, h + n);
  reverse(h, h + n);
  unsigned ll res = 0;
  for (int i = k; i < n; i++) {
    res += h[i];
  }
  cout << res << endl;
  return 0;

}
