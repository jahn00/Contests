/* 
    Author : Jeff Ahn
    Sat 15 Aug 2020 05:32:17 AM PDT 
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
int x, k, d;

signed main() {
  fastio;
  cin >> x >> k >> d;
  if (x < 0) x = -x;
  int m = x / d;
  if (m < k) {
    x -= m * d;
    k -= m;
    if (k % 2) {
      x = min(abs(x + d), abs(x - d));
    }
  } else {
    x -= d * k;
  }
  cout << x << endl;
  return 0;


}
