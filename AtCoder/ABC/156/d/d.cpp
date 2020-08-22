#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

inline int inverse(ll a) {
  ll u = 0, v = 1;
  ll m = mod;
  while (a != 0) {
    ll t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return (u + mod) % mod;
}

int binom(int n, int k) {
  ll res = 1;
  if (k > n -k) k = n-k;
  for (int i = 0; i < k; i++) {
    res = (res * (n-i)) % mod;
    res = (res * inverse(i+1)) % mod;
  }
  return res % mod;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

int modpow(int b, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) {
      res = mul(res, b);
    }
    b = mul(b, b);
    p >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int res = modpow(2, n);
  int ca = binom(n, a);
  int cb = binom(n, b);
  //cerr << ca << " " << cb << endl;
  res = (res - ca - 1+ mod) % mod;
  res = (res - cb + mod) % mod; 
  cout << res << endl;

}
