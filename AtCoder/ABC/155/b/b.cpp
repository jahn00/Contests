#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a & 1) continue;
    if (a % 3 != 0 && a % 5 != 0) {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
}

