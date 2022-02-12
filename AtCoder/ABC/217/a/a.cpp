/* 
    Author : Jeff Ahn
    Sat 04 Sep 2021 04:42:01 AM PDT 
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
  string s, t;
  cin >> s >> t;
  if (s < t) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
