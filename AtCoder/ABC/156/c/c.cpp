#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int x[100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  ll res = 0x3f3f3f3f3f3f3f3f;
  for (int p = -100; p <= 100; p++) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (x[i] - p) * (x[i] - p);
    }
    res = min(sum, res);
  }
  cout << res << endl;
}

