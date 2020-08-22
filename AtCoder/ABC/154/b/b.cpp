#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  string res;
  for(int i =0; i < n;i++) {
    res+='x';
  }
  cout << res << endl;
}
