/* 
    Author : Jeff Ahn
    Sun 14 Jun 2020 01:34:52 PM PDT 
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


signed main() {
  fastio;
  int x,y;
  cin >> x >> y;
  int b;
  b = y - 2*x;
  if (b < 0 || b % 2) {
    cout << "No" << endl;
    return 0;
  }
  b /= 2;
  if (x - b < 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
  
}
