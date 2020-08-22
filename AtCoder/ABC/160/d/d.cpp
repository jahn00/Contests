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
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> cnt(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int dist = (j - i);
      dist = min(dist, (abs(x - i) + 1 + abs(j - y)));
      cnt[dist]++;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << cnt[i] << endl;
  }

}
