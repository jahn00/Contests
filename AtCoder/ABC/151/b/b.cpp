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
  int N, K, M;
  cin >> N >> K >> M;
  int sum = 0;
  int a;
  rep(i, N - 1) {
    cin >> a;
    sum += a;
  }
  int res = M * N - sum;
  if (res > K) {
    cout << -1 << endl;
    return 0;
  }
  else if (res < 0) {
    cout << 0 << endl;
  }
  else 
  {
    cout << res << endl;
  }
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
