#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ull = unsigned long long;
template<typename T> void Out(T x) { cout << x << endl; }

ull nC2(ull a) {
  return (a)*(a-1)/2;
}

ull nC3(ull a) {
  return (a)*(a-1)*(a-2)/6;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n, nr = 0, ng = 0, nb = 0; string s;
  cin >> n >> s;
  ull choose3 = n * (n-1) * (n-2) / 6;
  rep(i,n) {
    if (s[i] == 'R') nr++;
    if (s[i] == 'G') ng++;
    if (s[i] == 'B') nb++;
  }

  ull res = choose3 - nC3(nr) - nC3(ng) - nC3(nb);
  res =  res - nC2(nr)*(ng + nb) - nC2(ng)*(nr + nb) - nC2(nb)*(ng + nr);
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + 2*len < n; i++) {
      if (s[i] == s[i + len] || s[i + len] == s[i + 2*len] || s[i] == s[i + 2*len]) {
        continue;
      }
      else res--;
    }
  }
  cout << res << endl;

}
