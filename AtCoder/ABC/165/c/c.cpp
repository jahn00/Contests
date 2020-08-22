//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
ll N, M, Q;
ll a[51], b[51], c[51], d[51];
ll maxi = -1;

void dfs(int num, vector<int>& res) {
  if (res.size() == N) {
    ll sum = 0;
    for (int i = 0; i < Q; i++) {
      if (res[b[i]] - res[a[i]] == c[i]) {
        sum += d[i];
      }
    }
    maxi = max(sum, maxi);
    return;
  }

  for(int i = num; i <= M; i++) {
    res.pb(i);
    dfs(i, res);
    res.pop_back();
  }
}

int main() {
  fastio;
  
  cin >> N >> M >> Q;
  rep(i, Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }
  vector<int> res;
  dfs(1, res);
  cout << maxi << endl;
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
