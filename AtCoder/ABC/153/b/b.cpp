#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int a[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double h;
  int n, i = 0;
  cin >> h >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  while(i < n && h > 0) {
    h -= a[i++];
  }
  if (h <= 0){ cout << "Yes" << endl; return 0; }
  else cout << "No" << endl; 
  return 0;
}
