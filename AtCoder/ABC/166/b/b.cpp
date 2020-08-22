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
  int N, K;
  cin >> N >> K;
  unordered_map<int,int> mp;
  rep(z, K) {
    int D;
    cin >> D;
    for (int i = 0; i < D; i++) {
      int A;
      cin >> A;
      mp[A]++;
    }
  }
  cout << (N - mp.size()) << endl;
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
