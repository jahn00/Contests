//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
int n; ll k;
int main() {
  fastio;
  cin >> n >> k;
  vector<ll> a(n + 1);
  vector<bool> visit(n+1, false);
  vector<ll> res;
  rep(i,n) cin >> a[i + 1];
  int curr = 1;
  while(!visit[curr]) {
    visit[curr] = true;
    res.push_back(curr);
    curr = a[curr];
  }
  ll sz = res.size(), i = 0;
  for (; i < sz; i++) {
    if (res[i] == curr) break;
  }
  if (i == sz) { 
    i = 0;
  }
  ll period = sz - i;
  // cout << i << " " << period << endl;
  if (k < i) { 
    cout << res[k] << endl;
    return 0;
  } else {
    k -= i;
    cout << res[k % period + i] << endl;
  }
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
