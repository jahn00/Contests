#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbgarr(x, sz)                                             \
    for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
    cout << endl;
#define dbgarr2(x, __rows, __cols)                \
    for (int asdf2 = 0; asdf2 < __rows; asdf2++) { \
        dbgarr(x[asdf2], __cols);                   \
    }
#define dbgstd(x)                                                           \
    for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
    cout << endl;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

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

signed main() {
    fastio;
    vector<Mint> a;
}
