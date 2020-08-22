/* 
    Author : Jeff Ahn
    Sat 15 Aug 2020 04:59:39 AM PDT 
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

  string s;
  cin >> s;
  int res = 0;
  if (s[1] == 'R') {
    res = 1;
    if (s[0] == 'R') {
      res++;
    }
    if (s[2] == 'R') {
      res++;
    }
  }
  else if (s[0] == 'R' or s[2] == 'R') res = 1;
  cout << res << endl;
  
}
