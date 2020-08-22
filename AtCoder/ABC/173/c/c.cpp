/* 
    Author : Jeff Ahn
    Sun 05 Jul 2020 05:08:27 AM PDT 
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

int k;
int count(int rmask, int cmask, vector<vector<char>> grid) {
  int R = grid.size(), C = grid[0].size();
  for (int i = 0; i < R; i++) {
    if (rmask & (1 << i)) {
      for (int c = 0; c < C; c++) {
        grid[i][c] = '_';
      }
    }
  }
  for (int i = 0; i < C; i++) {
    if (cmask & (1 << i)) {
      for (int r = 0; r < R; r++) {
        grid[r][i] = '_';
      }
    }
  }
  int cnt = 0;
  rep(r,R) {
    rep(c,C) {
      if (grid[r][c]=='#') cnt++;
    }
  }
  return cnt == k;
}

signed main() {
  fastio;
  int R, C;
  cin >> R >> C >> k;
  vector<vector<char>> grid(R,vector<char>(C));
  rep(r, R) {
    rep(c, C){
      cin >> grid[r][c];
    }
  }

  int res = 0;
  for (int i = 0; i < (1<<R); i++) {
    for (int j = 0; j < (1<<C); j++) {
      res += count(i,j,grid);
    }
  }
  cout << res << endl;

}
