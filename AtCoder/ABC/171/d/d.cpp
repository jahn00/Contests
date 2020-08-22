/* 
    Author : Jeff Ahn
    Sun 21 Jun 2020 04:45:00 PM PDT 
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

const int mxn = 1e5+1;
int f[mxn];

signed main() {
  fastio;
  int n; cin >> n;
  memset(f, 0, sizeof(f));
  int sum = 0;
  rep(i,n) {
    int ai;
    cin >> ai;
    f[ai]++;
    sum += ai;
  }

  int q;
  cin >> q;
  while(q--) {
    int bi, ci;
    cin >> bi >> ci;
    sum -= (bi * f[bi]);
    f[ci] += f[bi];
    int fb = f[bi];
    f[bi] = 0;
    sum += (ci * fb);
    cout << sum << endl;
  }

}
