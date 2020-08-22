//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;

inline ll pw(ll c) {
  return c*c*c*c*c;
}

inline ll f(ll a, ll b) {
  return pw(a) - pw(b);
}

int main() {
  fastio;
  int x; cin >> x;
  for (int a = -2000; a <= 2000; a++) {
    for (int b = -2000; b <= 2000; b++) {
      if (f(a,b) == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
