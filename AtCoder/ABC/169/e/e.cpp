/* Tue 02 Jun 2020 10:28:22 PM PDT */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

signed main() {
  fastio;
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  rep(i,n) {
    cin >> a[i] >> b[i];
  }
  sort(ALL(a));
  sort(ALL(b));
  int res = 0;
  if (n % 2) {
    res = b[n/2] - a[n/2] + 1;
  } else {
    int x = b[n/2-1] - a[n/2-1] + 1;
    int y = b[n/2] - a[n/2] + 1;
    res = y + x - 1; // subtract 1 (amin and bmax is counted twice)
  }
  cout << res << endl;
  
}
