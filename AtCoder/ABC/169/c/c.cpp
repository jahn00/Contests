#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
using ll = long long;
using ull = unsigned long long;

int main() {
  fastio;
  ull a; long double b;
  cin >> a >> b;

  int B = b * 100;
  cerr << B << endl;
  ull res = a * B;
  res /= 100;
  cout << res << endl;
}
