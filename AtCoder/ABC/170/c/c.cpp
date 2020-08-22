/* 
    Author : Jeff Ahn
    Sun 14 Jun 2020 01:37:23 PM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const map<T,T> &vec){ os<< "{"; for (auto p : vec) os << "(" << p.first << "," << p.second << "), "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_map<T,T>&vec){ os<< "{"; for (auto p : vec) os << "(" << p.first << "," << p.second << "), "; os << "}"; return os; }

int p[110];
signed main() {
  fastio;
  int x, n;
  cin >> x >> n;
  if (n == 0) { cout << x << endl; return 0; }
  rep(i, n) cin >> p[i];
  set<int> st;
  rep(j, n) {
      st.insert(p[j]);
  }
  set<int> stc;
  for (int i = 0; i <= 101; i++) {
    if (st.count(i)) continue;
    else stc.insert(i);
  }
  int res = 101, mini = 101;
  for (auto c : stc) {
    // cout << c << endl;
    if (abs(x - c) < mini) {
      mini = abs(x - c);
      res = c;
    }
  }
  cout << res << endl;
}
