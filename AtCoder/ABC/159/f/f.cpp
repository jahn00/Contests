/* 
    Author : Jeff Ahn
    Mon 22 Jun 2020 06:04:23 AM PDT 
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

/*
// (1) Creates a struct as a template for Mint.
struct VarMod { static unsigned value; };

// (2) Assigns a reference to the modulus in the newly crated struct.
unsigned VarMod::value = 1e9 + 7;

// uncomment if modulus needs to be changed during runtime
//unsigned& md = VarMod::modulus; 

// (3) Alias the templated class as Mint.
using Mint = Modular<VarMod>;
*/

constexpr unsigned md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

const int mxn = 3e3+10;
Mint a[mxn], f[mxn][mxn];

signed main() {
  fastio;
  int n, S;
  cin >> n >> S;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    int ai; cin >> ai;
    a[i] = Mint(ai);
  }

  for (int i = 1; i <= n; i++) {
    int ai = a[i].v;
    for (int j = 0; j + ai <= S; j++) {
      if (j == 0) f[i + 1][j] += i;
      else f[i + 1][j + ai] += f[i][j];
    }
    for (int k = 
  }

  Mint res(0);
  for (int i = 1; i <= n; i++) {
    Mint k(n - i + 1);
    res += f[i][S] * k;
  }
  cout << res.v << endl;

}
