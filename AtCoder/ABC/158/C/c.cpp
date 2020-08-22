#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= 1000; i++) {
    if ((i * 8 / 100) == a && (i / 10) == b ) {
      Out(i); return 0;
    }
  }
  Out(-1);
  return 0;
}
