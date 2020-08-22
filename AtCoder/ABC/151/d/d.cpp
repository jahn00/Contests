//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
int R, C;
int g[30][30];
int dist[30][30];
bool visit[30][30];
int dir[5] = { -1, 0, 1, 0, -1};
pair<int,int> st;

int bfs() {
  int maxi = 0;
  queue<pair<int,int>>q;
  q.push(st);
  memset(visit, false, sizeof(visit));
  memset(dist, false, sizeof(dist));
  while(!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n;i++) {
      auto top = q.front();
      q.pop();
      int r = top.first, c = top.second;
      visit[r][c] = true;
      for (int d = 0; d < 4; d++) {
        int dr = top.first + dir[d];
        int dc = top.second + dir[d + 1];
        if (dr < 0 || dr >= R || dc < 0 || dc >= C || visit[dr][dc] || g[dr][dc] == '#') continue;
        dist[dr][dc] = dist[r][c] + 1;
        visit[dr][dc] = true;
        if (dist[dr][dc] > maxi) {
          maxi = dist[dr][dc];
          st = {dr,dc};
        }
        q.push({dr,dc});
      }
    }
  }
  return maxi;
}

int main() {
  fastio;
  cin >> R >> C;
  memset(g, 0, sizeof(g));
  for (int r = 0; r < R; r++) {
    string row;
    cin >> row;
    for (int c = 0; c < C; c++) {
      g[r][c] = row[c];
      if (g[r][c] == '.') st = {r, c};
    }
  }
  int maxi = 0;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (g[r][c] == '.') {
        st = {r,c};
        maxi = max(maxi, bfs());
      }
    }
  }

  cout << maxi << endl;
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
