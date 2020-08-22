#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;


inline ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll h;
  cin >> h;
  int c = 0;
  while(h) h >>= 1, c++;
  cout << power(2, c) - 1 << endl;
}
