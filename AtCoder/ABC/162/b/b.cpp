#include <iostream>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;

  ll res = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 15 == 0) continue;
    else if (i % 3 == 0) continue;
    else if (i % 5 == 0) continue;
    else res += i;
  }
  cout << res << endl;


}
