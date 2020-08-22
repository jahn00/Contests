#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

signed main() {
  fastio;
  ll n, i=2; cin >> n;
  map<int,int> mp;
  for (; i * i <= n; i++) {
    if (n % i == 0) {
      int exp = 0;
      while (n % i == 0) {
        exp++; n/=i;
      }
      mp[i] = exp;
    }
  }
  if (n != 1) mp[n]++;
  ll res = 0;
  for (auto p : mp) {
    int exp = p.second;
    int sub = 1;
    while (exp - sub >= 0) {
      exp -= sub;
      sub++; 
      res++;
    }
  }
  cout << res << endl;
}
