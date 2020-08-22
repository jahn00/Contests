//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;

int A[13][13];

int main() {
  fastio;
  int R, C, X;
  cin >> R >> C >> X;
  vector<int> cost(R);
  for (int r = 0; r < R; r++) {
    cin >> cost[r];
    for (int c = 0; c < C; c++) {
      cin >> A[r][c];
    }
  }

  for (int c = 0; c < C; c++) {
    ull row = 0;
    for (int r = 0; r < R; r++) {
      row += A[r][c];
    }
    if (row < X) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  ull mini = 1e5 * 13;
  for (int m = 1; m < (1 << R); m++) {
    vector<int> rowsum(R,0);
    ull res = 0;
    for (int r = 0; r < R; r++) {
      if (m & (1 << r)) {
        res += cost[r];
        for (int c = 0; c < C; c++) {
          rowsum[c] += A[r][c];
        }
      }
    }
    bool valid = true;
    for (int c = 0; c < C; c++) {
      if (rowsum[c] < X) {
        valid = false;
        break;
      }
    }
    if (valid) {
      mini = min(mini, res);
    }
  }
  cout << mini << '\n';
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
