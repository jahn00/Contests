#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int maxi = 0;
  string s;
  cin >> n;

  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s]++;
    maxi = max(mp[s], maxi);
  }

  for (auto& p : mp) {
    if (p.second == maxi) {
      cout << p.first << endl;
    }
  }
  return 0;
}
