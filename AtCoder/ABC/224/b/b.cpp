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
#define printstd(x)                                                           \
    for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
    cout << endl;
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

signed main() {
    fastio;
    int R, C;
    cin >> R >> C;
    vector<vector<int>> a(R, vector<int>(C));
    rep(r, R) rep(c, C) cin >> a[r][c];

    for (int r = 0; r < R; r++) {
        for (int r2 = r + 1; r2 < R; r2++) {
            for (int c = 0; c < C; c++) {
                for (int c2 = c + 1; c2 < C; c2++) {
                    if (a[r][c] + a[r2][c2] > a[r2][c] + a[r][c2]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}