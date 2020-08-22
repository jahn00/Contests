#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int res = 0;
  while(n) {
    n /= k;
    res++;
  }
  cout << res << endl;
}
