/* 
    Author : Jeff Ahn
    Sat 27 Jun 2020 05:19:54 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int unsigned long long
// #define uint unsigned long long
#define endl '\n'

const int mn = 1e7 + 10;
int lp[mn], pr[mn];

signed main() {
  fastio;
  int n;
  cin >> n;

  memset(lp, 0, sizeof(lp));
  memset(pr, 0, sizeof(pr));
  pr[1] = 1;
  int pi = 0;
  for (int i = 2; i <= n; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr[pi++] = i;
    }
    for (int j = 0; j < (int) pi && pr[j] <= lp[i] && i * pr[j] <= n; j++) {
      lp[i * pr[j]] = pr[j];
    }
  }

  int res = 1;
  for (int i = 2; i <= n; i++) {
    int tmp = i;
    int prod = 1;
    while(tmp != 1) {
      int smallest = lp[tmp];
      int cnt = 0;
      while (tmp % smallest == 0) {
        tmp /= smallest;
        cnt++;
      }
      prod *= (cnt + 1);
    }

    res += i * prod;
  }
  cout << res << endl;
}
