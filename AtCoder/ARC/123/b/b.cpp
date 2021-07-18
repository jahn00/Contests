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
#define int long long
#define uint unsigned long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

signed main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));

    int i = 0, j = 0, k = 0, res = 0;
    for (; i < n; i++, j++, k++) {
        int ai = a[i];
        while (j < n and ai >= b[j]) j++;
        if (j == n) break;
        int bj = b[j];
        while (k < n and bj >= c[k]) k++;
        if (k == n) break;
        res++;
        //cout << a[i] << " " << b[j] << " " << c[k] << endl;
    }
    cout << res << endl;
    return 0;
}