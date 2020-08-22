/* 
    Author : Jeff Ahn
    Sun 05 Jul 2020 05:25:05 AM PDT 
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

int n;
const int mn = 2e5+10;
int a [mn];

signed main() {
  fastio;
  cin >> n;
  rep(i,n) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  int res = a[0];
  for (int i = 1; i < n/2; i++) {
    int ai = a[i];
    res += ai + ai;
  }
  if (n&1) res += a[n/2];
  cout << res << endl;
}
