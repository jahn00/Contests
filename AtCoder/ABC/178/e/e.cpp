#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>
#include <bitset>
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
 
 
signed main() {
    fastio;
    int n; cin >> n;
    // vector<pair<int,int>> a(n);
    set <pair<int,int>> st;
    rep (i, n) {
        int x, y;
        cin >> x >> y;
        st.insert(make_pair(x, y));
    }
    int maxi = -1, mini = inf;
    for (auto& p : st) {
        int x = p.first, y = p.second;
        maxi = max(maxi, x + y);
        mini = min(mini, x + y);
 
    }
    int res = abs(maxi - mini);
    cout << res << endl;
 
    return 0;
 
}