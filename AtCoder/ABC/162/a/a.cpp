#include <bits/stdc++.h>
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
  while(n) {
    if (n%10 == 7) {
      cout << "Yes" << endl;
      return 0;
    }
    n /= 10;
  }
  cout << "No" << endl;
  return 0;
}
