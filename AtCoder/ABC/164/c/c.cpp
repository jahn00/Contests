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
  int N;
  unordered_map<string , int> mp; // kind -> count
  cin >> N;
  rep(i, N) {
    string kind;
    cin >> kind;
    mp[kind]++;
  }
  cout << mp.size() << endl;
  
  #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
