/* 
    Author : Jeff Ahn
    Wed 01 Jul 2020 08:37:43 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

template <typename T> struct Modular {
  /* to abbreviate the word "Modular" */
  using M = Modular; 

  /* Infers type from template. The struct/class T must have 
     "modulus" defined as member.*/
  using Type = typename decay<decltype(T::value)>::type; 

  /* Mod() is now an alias to the "modulus" (eg 1e9+7) */
  constexpr static Type Mod() { return  T::value; }

  /* v is the value of the Mint. [0 <= v < Mod) */
  Type v;
  Modular(long long a = 0) : v((a %= Mod()) < 0 ? a + Mod() : a) {}
  M operator-() const { return M() -= *this; }
  M& operator+=(M r) { if ((v += r.v) >= Mod()) v -= Mod(); return *this; }
  M& operator-=(M r) { if ((v += Mod() - r.v) >= Mod()) v -= Mod(); return *this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % Mod(); return *this; }
  M& operator/=(M r) { return *this *= mdpow(r, Mod() - 2); }
  M& operator++() { return *this += M(1); };
  M& operator--() { return *this -= M(1); };
  friend M operator+(M l, M r) { return l += r; }
  friend M operator-(M l, M r) { return l -= r; }
  friend M operator*(M l, M r) { return l *= r; }
  friend M operator/(M l, M r) { return l /= r; }
  friend bool operator==(M l, M r) { return l.v == r.v; }
  friend M mdpow(M b, unsigned exp) {
    Modular res(1);
    while(exp) {
      if (exp & 1) {
        res *= b;
        if ((res.v += Mod()) >= Mod()) res.v -= Mod();
      }
      b *= b;
      exp >>= 1;
    }
    return res;
  }
};

constexpr unsigned md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

const int mn = 5e5 + 10;
Mint fact[mn], ifact[mn];

void prep(int _N) {
  fact[0] = Mint(1);
  for (int i = 1; i <= _N; ++i) fact[i] = Mint(i) * fact[i - 1];

  ifact[_N] = mdpow(fact[_N], md-2);
  for (int i = _N; i > 0; --i) ifact[i - 1] = Mint(i) * ifact[i];
}

Mint binom(int _N, int k) {
  if (k < 0 || k > _N) return 0;
  return fact[_N] * ifact[k] * ifact[_N - k];
}

signed main() {
  fastio;
  int n, m;
  cin >> n >> m;
  prep(m);

  Mint res(0);
  for (int i = 0; i <= n; i++) {
    Mint c = binom(n,i) * binom(m - i, n - i) * fact[n - i];
    if (i&1) res -= c;
    else res += c;
  }
  res *= (binom(m,n) * fact[n]);
  cout << res.v << endl;
}
