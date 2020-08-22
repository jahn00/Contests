/* 
    Author : Jeff Ahn
    Sat 27 Jun 2020 05:03:38 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int unsigned long long
#define endl '\n'
int n, m, k;
const int mn = 200010;
int a[mn], b[mn];

signed main() {
  fastio;
  cin >> n >> m >> k;
  rep(i, n) {
    cin >> a[i];
  }
  rep(i,m) {
    cin >> b[i];
  }

  int i = 0, j = 0, res = 0;

  while((i < n && j < m) && k >= min(a[i], b[j])) {
    if (a[i] <= b[j]) {
      k -= a[i]; i++;
    } else {
      k -= b[j]; j++;
    }
    res++;
  }

  if (i == n && j < m) {
    while (j < m && k >= b[j]) { 
      j++; res++;
    }
  }
  else if (i < n && j == m) {
    while (i < n && k >= a[i]) { 
      i++; res++;
    }
  }
  cout << res << endl;

}
