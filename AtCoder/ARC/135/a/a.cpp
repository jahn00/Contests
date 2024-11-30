/* 
    Author : Jeff Ahn
    Sun 13 Feb 2022 03:49:41 AM PST 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
 
const int md = 998244353;

using ll = long long;

unordered_map<ll, int> mp;

int f(long long n) {
    if (n == 2) return 2;
    if (n == 3) return 3;
    if (n == 4) return 4;
    if (mp.count(n)) return mp[n];
    int& res = mp[n];
    res = (1LL * f(n/2) * f((n + 1) / 2)) % md;
    return res;
}
 
signed main() {
    fastio;
    long long N; cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    int res = f(N);
    cout << res << endl;


    return 0;
}