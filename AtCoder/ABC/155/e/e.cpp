#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

string s;
int n;
const int mn = 1e6+1;
int f[mn][2];

int solve(int idx, int c) {
  if (idx == n) return c;
  int& res = f[idx][c];
  if (~res) return res;
  res = 1e9; 
  int amt = s[idx] - '0' + c;
  if (amt < 10) {
    res = min(res,solve(idx + 1, 0) + amt);
  }
  res = min(res, solve(idx + 1, 1) + 10-amt);
  return res;
}

signed main() {
  fastio;
  cin >> s;
  n = s.size();
  reverse(all(s));
  memset(f,-1, sizeof(f));
  cout << solve(0,0) << endl;
}
