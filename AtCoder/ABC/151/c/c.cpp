//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
int N, M;
int main() {
  fastio;
  cin >> N >> M;
  vector<pair<int,int>> sub(N+1, {0,0});
  int p; string s;
  int ans = 0, pen = 0;
  rep(i, M) {
    cin >> p >> s;
    if (sub[p].first == 1) continue;
    if (s == "AC") {
      ans++;
      pen += sub[p].second;
      sub[p].first = 1;
    } else {
      sub[p].second++;
    }
  }
  cout << ans << " " << pen << '\n';
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
