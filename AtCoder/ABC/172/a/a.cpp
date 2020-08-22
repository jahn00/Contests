/* 
    Author : Jeff Ahn
    Sat 27 Jun 2020 04:54:56 AM PDT 
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

signed main() {
  fastio;
  int a;
  cin >> a;
  int res = 0;
  res = a + a*a + a*a*a;
  cout << res << endl;
}
