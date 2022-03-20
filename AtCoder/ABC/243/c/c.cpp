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
    int n; cin >> n;

    vector<pair<int,int>> a(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }

    unordered_map<int, set<pair<int, char>>> rows; // row -> set of x's and directions
    string s; cin >> s;
    rep(i, n) {
        char c = s[i];
        int x = a[i].first;
        int y = a[i].second;
        rows[y].emplace(x, c);
    }
    for (auto r : rows) {
        bool R_found = false;
        for (auto p : r.second) {
            R_found |= p.second == 'R';

            if (R_found and p.second == 'L') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}