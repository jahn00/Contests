/* 
    Author : Jeff Ahn
    Sun 05 Jul 2020 04:51:01 AM PDT 
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
  int n;
  cin >> n;
  int pay = 1000;
  if (n % pay) {
    cout << pay - n % pay << endl;
  } else {
    cout << 0 << endl;
  }
}
