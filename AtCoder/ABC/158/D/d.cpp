#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

// 0 = all front chars
// 1 = all back chars
vector<char> qu[2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; int Q;
  cin >> s >> Q;
  bool rev = false;
  while(Q--) {
    int q;
    cin >> q;
    // rev string
    if (q == 1) {
      rev = !rev;
    }
    else {
      int f; char c;
      cin >> f >> c;
      f--; // f == 0 or 1, front or back resp.
      qu[f ^ rev].push_back(c);
    }
  }
  string res;
  for (int i = qu[0].size() - 1; i >= 0; i--)
    res += qu[0][i];
  res += s;
  for (auto c : qu[1]) res += c;
  if (rev) {
    reverse(res.begin(), res.end());
  }
  cout << res << endl;
}
