#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using ull = unsigned long long;

int main() {
  fastio;
  int N; cin >> N;
  unordered_map<int, int> mp; // boss -> subs cnt
  int a;
  rep(i,0,N-1) {
    cin >> a;
    mp[a]++;
  }
  for (int i = 1; i <= N; i++) {
    cout << mp[i] << endl;
  }
  return 0;
}
