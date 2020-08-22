#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

signed main() {
  fastio;
  int k;
  cin >> k;
  if (k % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  else {
    int md = 0, i = 0;
    do {
      md *= 10;
      md += 7;
      if (md >= k) md -= k;
      cout << i << endl;
      i++;
    } while (md != 0);
    cout << i << endl;
    return 0;
  }
}
