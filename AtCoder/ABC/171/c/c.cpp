/* 
    Author : Jeff Ahn
    Sun 21 Jun 2020 03:32:55 PM PDT 
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
  vector<char>c(27, 'a');
  for (int i = 0; i < 26; i++) {
    c[i+1] += i;
  }
  c[0] = 'z';
  string res = "";
  while (n) {
    int co = n % 26;
    res += c[co];
    if (co == 0) {
      n -= 26;
    }
    n /= 26;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;

}
