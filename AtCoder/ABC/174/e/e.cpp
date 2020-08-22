/* 
    Author : Jeff Ahn
    Sun 02 Aug 2020 08:56:58 PM PDT 
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

int n, k;
const int mn = 2e5+1;
int a[mn];
signed main() {
  fastio;
  cin >> n >> k;
  int r = 1e9+10;
  rep(i,n) {
    int ai;
    cin >> ai;
    a[i] = ai;
    r = max(r, ai);
  }

  int l = 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int cuts = 0;
    rep(i,n) {
      int ai = a[i];
      cuts += (ai - 1) / mid;
    }
    if (cuts <= k) {
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << l << endl;
}
