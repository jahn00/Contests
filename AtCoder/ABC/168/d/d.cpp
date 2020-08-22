//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
using vvi = vector<vector<int>>;
const int maxn = 1e5 + 10;
const int maxm = 2e5 + 10;

struct edge {
  int to, from;
  int best;
  edge(int t, int f) {to=t;from=f;}
};

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  vector<vector<edge>> g(n+1);
  int a, b;
  for (int i = 0; i < m; i ++ ) {
    cin >> a >> b;
    g[a].push_back({b,a});
    g[b].push_back({a,b});
  }

  vector<int> visit(n+1, 0);
  vector<int> res(n+1);
  queue<int> q;
  visit[1] = true;
  q.push(1);
  while(!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; i++) {
      int top = q.front(); q.pop();
      for (auto e : g[top]) {
        if (!visit[e.to]) {
          visit[e.to] = true;
          res[e.to] = top;
          q.push(e.to);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (visit[i] == false) {
      cout << "No" << endl; return 0;
    }
  }

  cout << "Yes\n";
  for (int i = 2; i <= n; i++) {
    cout << res[i] << '\n';
  }
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
