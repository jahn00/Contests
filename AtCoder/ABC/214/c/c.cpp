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
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

const int mn = 2e5 + 10;
int a[2 * mn];
int times[mn];

signed main() {
    fastio;
    int n; cin >> n;
    int mini = inf, start;
    rep(i, n) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    rep(i, n) {
        cin >> times[i];
        if (times[i] < mini) {
            mini = times[i];
            start = i;
        }
    }

    vector<int> res(n);
    int t = mini;
    for (int i = 0; i < n; i++) {
        int j = (i + start) % n;
        t = min(t + a[j - 1], times[j]);
        res[j] = t;
    }

    rep(i, n) cout << res[i] << endl;
    return 0;

}