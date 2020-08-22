/* 
    Author : Jeff Ahn
    Fri 19 Jun 2020 05:04:39 AM PDT 
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
int pre[12][1010];
string g[12];
int R, C, k;

inline int get(int r1, int c1, int r2, int c2) {
  return pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1];
}

signed main() {
  fastio;
  cin >> R >> C >> k;
  
  rep(r, R) { 
    cin >> g[r];
    rep(c,  C) {
      g[r][c] -= '0';
    }
  }

  memset(pre, 0, sizeof(pre));
  rep(r, R) { 
    rep(c, C) {
      pre[r + 1][c + 1] = pre[r][c+1] + pre[r+1][c] - pre[r][c] + g[r][c];
    }
  }

  int res = 0x3f3f3f3f;
  for (int tri = 0; tri < (1 << (R-1)); tri++) {
    vector<int> segs;
    int cuts = 0;
    segs.pb(0);
    for (int r = 0; r < R-1; r++) {
      if (tri & (1 << r)) {
        segs.pb(r + 1);
        cuts++;
      }
    }
    segs.pb(R);
    //for (auto c : segs) cout << c << " "; cout << endl;
    bool badd = false;
    int vcut = 0;
    for (int c = 1; c <= C; c++) {
      bool bad = false;
      for (int hcut = 0; hcut + 1 < segs.size(); hcut++) {
        /* cout << "(" << segs[hcut] << ", " <<  vcut << ") ";
        cout << "( " << segs[hcut + 1] << ", " << c << ") " << endl;
        */
        assert(segs[hcut] < segs[hcut + 1]);
        int cnt = get(segs[hcut], vcut, segs[hcut + 1], c);
        //cerr << cnt << endl;
        if (cnt > k) {
          bad = true;
          break;
        }
      }
      if (bad && c - vcut <= 1) {
        badd = true;
        break;
      } 
      else if (bad) {
        vcut = c - 1;
        c--;
        // cout << vcut << " " << c << endl;
        cuts++;
      }
    }
    if (!badd)
      res = min(res, cuts);
  }
  cout << res << endl;
}
