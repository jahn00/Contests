/* 
    Author : Jeff Ahn
    Sun 21 Jun 2020 05:16:20 PM PDT 
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

const int mxn = 2e5 + 10;
int a[mxn];

signed main() {
  fastio;
  int n;
  cin >> n;
  int sum = 0;
  rep(i,n) { cin >> a[i]; sum ^= a[i]; }
  rep(i,n) cout << (a[i] ^ sum) << endl;
}
