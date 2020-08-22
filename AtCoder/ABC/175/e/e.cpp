/* 
    Author : Jeff Ahn
    Sat 15 Aug 2020 06:08:29 AM PDT 
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

int inf = 0x3f3f3f3f3f3f3f3f;
int R,C,K;
const int mn = 3010;
int f[mn][mn][4];
int g[mn][mn];

int dfs(int r, int c, int k) {
  if (r > R or c > C or r < 1 or c < 1) return 0;
  int& res = f[r][c][k];
  if (~res) return res;

  res = 0;
  int grc = g[r][c];

  res = max(dfs(r+1, c, 3), dfs(r, c+1, nk)) + grc;

  return res;

}

signed main() {
  fastio;
  cin >> R >> C >> K;
  memset(f, -1, sizeof f);
  memset(g, 0, sizeof g);
  rep(k, K) {
    int r, c;
    cin >> r >> c;
    cin >> g[r][c];
  }
  cout << dfs(R, C, 3) << endl;
  return 0;
}
