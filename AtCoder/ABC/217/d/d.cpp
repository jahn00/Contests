/* 
    Author : Jeff Ahn
    Sat 04 Sep 2021 05:14:49 AM PDT 
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

int L, Q;
signed main() {
  fastio;
  cin >> L >> Q;

  set<int> cuts;
  cuts.insert(0);
  cuts.insert(L);
  rep(_, Q) {
    int qi, xi;
    cin >> qi >> xi;

    if (qi == 1) {
      // cut the segment at xi
      cuts.insert(xi);
    }
    else {
      // print the segment length that xi is on

      auto left = --cuts.lower_bound(xi);
      auto right = cuts.lower_bound(xi);
      //cerr << "left: " << *left << " right: " << *right << endl;
      cout << *right - * left << endl;
    }

  }

}
