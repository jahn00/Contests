/* 
    Author : Jeff Ahn
    Sat 04 Sep 2021 05:06:00 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

signed main() {
  fastio;
  int N;
  cin >> N;
  vector<int> P(N + 1), Q(N + 1);
  rep(i, N) cin >> P[i+ 1];

  for (int i = 1; i <= N; i++) {
    Q[P[i]] = i;
  }
  for (int i = 1; i <= N; i++) {
    cout << Q[i] << " ";
  }
  cout << endl;
}
