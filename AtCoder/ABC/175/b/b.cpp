/* 
    Author : Jeff Ahn
    Sat 15 Aug 2020 05:05:30 AM PDT 
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

const int mn = 110;
int l[mn];

signed main() {
  fastio;

  int N; cin >> N;
  rep(i,N) {
    cin >> l[i];
  }

  int res = 0;
  for (int i = 0; i < N; i++) {
    int li = l[i];
    for (int j = i + 1; j < N; j++) {
      int lj = l[j];
      if (li == lj) continue;
      for (int k = j + 1; k < N; k++) {
        int lk = l[k];
        if (lk == li or lk == lj) continue;
        if (li + lj > lk and li + lk > lj and lk + lj > li) {
          res++;
        }
      }
    }
  }
  cout << res << endl;
}
