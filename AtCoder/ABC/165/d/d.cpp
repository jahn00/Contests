//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;

ull a,b,n;
ll f(ll x) {
  return floor(a*x/b) - a*floor(x/b);
}


int main() {
  fastio;
  cin >> a >> b >> n;
  ll lo = -1;
  ull hi = n;
  while(hi - lo > 1) {
    ll mid = (hi + lo) >> 1;
    if (f(mid) > f(mid + 1)) {
      hi = mid;
    }
    else {
      lo = mid;
    }
  }
  cout << f(lo + 1) << endl;
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
