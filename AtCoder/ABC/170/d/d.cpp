/* 
    Author : Jeff Ahn
    Mon 29 Jun 2020 04:24:51 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
#define TIMER_

const int maxi = 1000010;
int a[maxi], p[maxi];

signed main() {
  fastio;
  int n;
  cin >> n;
  rep(i,n) cin >> a[i];

  memset(p, 0, sizeof(p));
  for (int i = 0; i < n; i++) {
    int ai = a[i];
    p[ai]++;
  }

  for (int i = 1; i < maxi; i++) {
    if (p[i]) {
      for (int j = i + i; j < maxi; j += i) {
        p[j]++;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int ai = a[i];
    if (p[ai] == 1) {
      res++;
    }
  }
  cout << res << endl;
#ifdef TIMER_
      cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
