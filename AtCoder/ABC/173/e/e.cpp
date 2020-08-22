/* 
    Author : Jeff Ahn
    Sun 05 Jul 2020 06:57:41 AM PDT 
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

const int mn = 100;
int a[mn][mn];
signed main() {
  fastio;
  rep(i,mn){
    fill(a[i],a[i]+mn,1);
  }
  rep(i,mn){
    rep(j,mn){
    cout << a[i][j] << " ";
    }
  }

}
