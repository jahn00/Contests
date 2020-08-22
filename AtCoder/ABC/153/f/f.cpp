#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
int n, rad, dam;
pair<int,int> coor[200010];

signed main() {
  fastio;
  cin >> n >> rad >> dam;
  rep(i,n) {
    cin >> coor[i].first >> coor[i].second;
  }
  sort(coor, coor + n);
}
