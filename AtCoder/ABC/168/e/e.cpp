#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
const long long mod = 1000000007;
long long pw[200200] = { 1 };

signed main() {
  fastio;
	map<pair<ll, ll>, pair<ll, ll> > chk;

	for (int i = 1; i < 200200; i++) pw[i] = (pw[i - 1] * 2) % mod;

	ll z = 0;
	int n; cin >> n;
  while (n--){
	  ll a, b; cin >> a >> b;
		if (a == 0 && b == 0){ z++; continue; }
    else if (a == 0) {
      chk[make_pair(0, 1)].first++;
    } 
    else if (b == 0) {
      chk[make_pair(0, 1)].second++;
    }
    else {
      ll g = __gcd(abs(a), abs(b));
      a /= g; b /= g;
      if (a * b > 0) {
        chk[make_pair(abs(a),abs(b))].first++;
      } 
      else {
        chk[make_pair(abs(b),abs(a))].second++;
      }
    }
	}

	ll r = 1;
	for (auto& p : chk) {
    // subtract the intersection (null set)
		r = r * (pw[p.second.first] + pw[p.second.second] - 1) % mod;
	}

  // exactly one of the sets in the big cross product is empty, which we 
  // omit (all subsets must be non-empty)
	cout << (z + r - 1 + mod) % mod << "\n";
}
