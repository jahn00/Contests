#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s,t, u;
  int a,b;
  cin >> s >> t;
  cin >> a >> b;
  cin >> u;
  if (s == u) a--;
  else if (u == t) b--;
  cout << a << " " << b;

}
