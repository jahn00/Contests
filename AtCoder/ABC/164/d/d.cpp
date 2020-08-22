//#define LOCAL_DEFINE
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using ull = unsigned long long;

const int maxn = 2e6 + 10;
int pre[maxn];

int main() {
  fastio;
  string s;
  cin >> s;
  reverse(ALL(s));
  vector<int> mp(2019, 0); // residue -> cnt
  mp[0] = 1;
  int base = 1;
  int sum = 0;
  rep(i, s.size()) {
    sum = sum + (s[i] - '0') * base;
    sum %= 2019;

    mp[sum]++;

    base *= 10;
    base %= 2019;
  }

  ull ans = 0;
  for (auto a : mp) {
    ans += (a*(a-1))/2;
  }
  cout << ans << '\n';

  
  #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
