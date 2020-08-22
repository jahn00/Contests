#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
const int maxn = 1e5 + 10;
ll A[maxn];

ll LCM(ll a, ll b) {
  return a / __gcd(a,b) * b;
}

int main() {
  fastio;
  ll N, M;
  cin >> N >> M;
  ll lcm = 1;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] /= 2;
    lcm = LCM(lcm, A[i]);
    if (lcm > M) {
      cout << 0 << endl;
      return 0;
    }
  }

  // check to make sure A[i]/2 is a multiple of an odd
  for (int i = 0; i < N; i++) {
    if ((lcm / A[i]) % 2 == 0) {
      cout << 0 << endl; return 0;
    }
  }
  lcm = 1;
  rep(i, N) {
    lcm = LCM(lcm, A[i]*2);
  }
  // cerr << "LCM: " << lcm << endl;
  ll res = M/lcm;
  // count every other multiple (odds) of the lcm
  // since counting the even multiples makes A[i]/2 * (2p + 1) = lcm false
  // the power of 2's in both A[i]/2 and lcm must be exactly the same
  res = (res + 2 - 1) / 2;
  cout << res << endl;
  
}
