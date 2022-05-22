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

signed main() {
    fastio;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int best = -1;
    rep (i, n) {
        cin >> a[i];
        best = max(best, a[i]);
    }
    bool res = false;
    rep (i, k) {
        int b; cin >> b;
        b--;
        res |= (best == a[b]);
    }
    if (res) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}