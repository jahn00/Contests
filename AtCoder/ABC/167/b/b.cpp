//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;

int main() {
  fastio;
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  int res = 0;
  if (k - a <= 0) {
    cout << k << endl;
    return 0;
  } 
  else {
    res += k;
    k -= a;
  }
  if (k - b <= 0) {
    cout << a << endl;
    return 0;
  } else {
    k -= b;
    cout << a - k << endl;
    return 0;
  }
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
