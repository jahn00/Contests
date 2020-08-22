#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ull = unsigned long long;
template<typename T> void Out(T x) { cout << x << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull r, b, N;
  cin >> N >> r >> b;
  Out(N/(r+b)*r + min(N % (r + b), r));
  return 0;
}
