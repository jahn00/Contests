#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

const int mn = 2e5+1;
char a[mn];

signed main() {
  fastio;
  int n; cin >> n;
  int w = 0, r = 0;
  rep(i, n) {
    char ai;
    cin >> ai;
    a[i] = ai;
    if (ai == 'W') w++;
    else r++;
  }

  int res = 0;
  rep(i, r) {
    char& ai = a[i];
    if (ai == 'W') res++;
  }
  cout << res << endl;
}
