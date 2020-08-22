#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using ull = unsigned long long;

int main() {
  fastio;
  int h1, a1, h2, a2;
  cin >> h1 >> a1 >> h2 >> a2;

  bool turn = true;
  while(h1 > 0 && h2 > 0) {
    if (turn) {
      h2 -= a1;
      turn = false;
    }
    else { h1 -= a2;
    turn = true;
    }
  }
  if (h1 <= 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  
  #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
