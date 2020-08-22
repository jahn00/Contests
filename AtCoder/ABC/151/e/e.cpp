#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
const int maxn = 100010;
int N, K;
int A[maxn];

template <unsigned Mod> struct Modular {
  using M = Modular;
  unsigned v;
  Modular(long long a = 0) : v((a %= Mod) < 0 ? a + Mod : a) {}
  M operator-() const { return M() -= *this; }
  M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
  M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % Mod; return *this; }
  M& operator/=(M r) { return *this *= mdpow(r, Mod - 2); }
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
        if ((res.v += Mod) >= Mod) res.v -= Mod;
      }
      b *= b;
      exp >>= 1;
    }
    return res;
  }
};

constexpr long long mod = 1e9 + 7;
using Mint = Modular<mod>;

vector<Mint> fact, inv_fact, minv;
void prep(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = 1 / fact[n];
  // cout << inv_fact[n].v << endl;
  for (int i = n; i; --i) inv_fact[i - 1] = i * inv_fact[i];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}

Mint binom(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int main() {
  fastio;
  cin >> N >> K;
  prep(N);
  // rep(i, N) cout << inv_fact[i].v << endl;
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  sort(A, A + N);
  Mint res(0);
  Mint choose;

  for (int i = 0; i < N; i++) {
    choose = binom(i, K-1);
    Mint val(A[i]);
    res += (val * choose);
  }

  for (int i = 0; i < N; i++) {
    Mint val(A[i]);
    choose = binom(N - i - 1, K-1);
    res -= (val * choose);
  }
  cout << res.v << endl;
}
