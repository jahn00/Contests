/* 
    Author : Jeff Ahn
    Thu 11 Jun 2020 06:19:11 PM PDT 
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
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const map<T,T> &vec){ os<< "{"; for (auto p : vec) os << "(" << p.first << "," << p.second << "), "; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_map<T,T>&vec){ os<< "{"; for (auto p : vec) os << "(" << p.first << "," << p.second << "), "; os << "}"; return os; }
const int mxn = 1e5 + 10;
int a[mxn], pre[mxn];

signed main() {
  fastio;
  int n, m;
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  sort(a, a + n);

  // prefix sums
  pre[0] = 0;
  rep(i,n) {
    pre[i + 1] = pre[i] + a[i];
  }
  int lo = 0, hi = 2e10, res, cnt, j;
  while(lo <= hi) {
    // mid is the min sum
    int mid = lo + (hi - lo) / 2;

    // count pairs whose sums are >= than mid
    cnt = 0; 
    j = n - 1;
    res = 0;
    for (int i = 0; i < n; i++) {
      while(j >= 0 && a[i] + a[j] >= mid) j--;
      cnt += (n - j - 1);
      res += (a[i] * (n - j - 1) + pre[n] - pre[j + 1]);
    }

    // if cnt is greater or equal than m, make sum (mid) larger (fewer pairs)
    // else make sum (mid) smaller
    if (cnt > m) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cnt -= m;
  res -= (cnt * lo);
  cout << res << endl;

}
