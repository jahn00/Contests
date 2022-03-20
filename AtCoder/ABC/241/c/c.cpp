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

int n;
vector<vector<int>> m;

signed main() {
    fastio;
    cin >> n;
    m.assign(n, vector<int>(n, 0));

    rep(r, n) {
        string s;
        cin >> s;
        rep(c, n) {
            m[r][c] = s[c] == '#';
        }
    }

    rep(r, n) {
        int row_count = 0;
        rep(c, n) {
            row_count += m[r][c];
            if (c >= 6) {
                row_count -= m[r][c - 6];
            }
            if (row_count >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    rep(c, n) {
        int col_count = 0;
        rep(r, n) {
            col_count += m[r][c];
            if (r >= 6) {
                col_count -= m[r - 6][c];
            }
            if (col_count >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    rep(r, n - 6 + 1) {
        rep(c, n - 6 + 1) {
            int cnt = 0, cnt2 = 0;
            rep(i, 6) {
                cnt += m[r + i][c + i];
                cnt2 += m[r + i][c + 6 - 1 - i];
            }
            if (cnt >= 4 or cnt2 >= 4) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}