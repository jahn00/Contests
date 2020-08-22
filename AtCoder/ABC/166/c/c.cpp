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
  vector<int> H(N, 0); // heights of ith hill
  rep(i, N) {
    cin >> H[i];
  }
  vector<int> indeg(N, 0);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (H[a] > H[b]) {
      indeg[b]++;
    } else if (H[a] < H[b]) indeg[a]++;
    else {
      indeg[a]++; indeg[b]++;
    }
  }

  int res = 0;
  for (auto a : indeg) {
    if (!a) res++;
  }
  cout << res << endl;

  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
