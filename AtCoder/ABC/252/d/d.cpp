#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>
#define print(x) cout << (#x) << " is " << (x) << endl;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;

using ll = long long;

ll nc3(ll n) {
    return n * (n - 1) * (n - 2) / 6;
}

ll nc2(ll n) {
    return n * (n - 1) / 2;
}

signed main() {
    fastio;
    int n; cin >> n;
    vector<ll> a(n);
    unordered_map<int, vector<int>> mp; // val -> [idxs]
    rep(i, n) {
        int x; cin >> x;
        a[i] = x;
        mp[x].push_back(i);
    }
    ll res = nc3(n);
    //cerr << "initial nc3: " << res << nl;
    int uniques = mp.size();

    for (auto p : mp) {
        int val = p.first;
        int count = p.second.size();
        res -= nc3(count);
        res -= (nc2(count) * (n - count));
    }
    cout << res << endl;
}