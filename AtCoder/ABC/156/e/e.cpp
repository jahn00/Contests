#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

int inverse(ll a) {
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
  if (k > n -k) k = n - k;

  for (int i = 0; i < k; i++) {
    res = mul (res, (n-i));
    res = mul (res, inverse(i+1));
    cout << res << endl;
  }
  return res % mod;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  cout << binom(n + k, k) << endl;



}

