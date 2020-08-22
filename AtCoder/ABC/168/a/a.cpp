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
  int n; cin >> n;
  int l = n % 10;
  if (l == 3) {
    cout << "bon" << '\n';
  } else if (l == 0 || l == 1 || l == 6 || l == 8) {
    cout << "pon" << '\n';
    return 0;
  } else {
    cout << "hon" << endl;
  }
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
