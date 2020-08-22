#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

vector<int> coins = {500 ,100, 50, 10, 5, 1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x; cin >> x;
  int res = 0;
  res += (x/500) * 1000;
  x %= 500;
  res += (x/5) * 5;
  cout << res << endl;
}
