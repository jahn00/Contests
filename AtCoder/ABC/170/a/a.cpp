/* 
    Author : Jeff Ahn
    Sun 14 Jun 2020 01:28:26 PM PDT 
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
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  if (!a)
    cout << 1 << endl;
  else if (!b) 
    cout << 2 << endl;
  else if (!c) 
    cout << 3 << endl;
  else if (!d) 
    cout << 4 << endl;
  else if (!e) 
    cout << 5 << endl;
  
}
