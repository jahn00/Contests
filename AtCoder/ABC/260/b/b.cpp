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
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;


signed main() {
    fastio;
    int n, X, Y, Z;
    cin >> n >> X >> Y >> Z;
    vector<std::array<int, 3>> a(n);
    rep (i, n) {
        cin >> a[i][0];
        a[i][2] = i + 1;
    }
    rep (i, n) {
        cin >> a[i][1];
    }

    sort(all(a), [&](const auto& lhs, const auto& rhs) {
        int lx = lhs[0], rx = rhs[0];
        // int ly = lhs[1], ry = rhs[1];
        int li = lhs[2], ri = rhs[2];
        return make_pair(-lx, li) > make_pair(-rx, ri);
    });

    vector<int> res;

    rep (i, X) {
        res.push_back(a.back()[2]);
        a.pop_back();
    }

    sort(all(a), [&](const auto& lhs, const auto& rhs) {
        // int lx = lhs[0], rx = rhs[0];
        int ly = lhs[1], ry = rhs[1];
        int li = lhs[2], ri = rhs[2];
        return make_pair(-ly, li) > make_pair(-ry, ri);
    });

    rep (i, Y) {
        res.push_back(a.back()[2]);
        a.pop_back();
    }

    sort(all(a), [&](const auto& lhs, const auto& rhs) {
        int lx = lhs[0], rx = rhs[0];
        int ly = lhs[1], ry = rhs[1];
        int li = lhs[2], ri = rhs[2];
        return make_pair(-ly - lx, li) > make_pair(-ry - rx, ri);
    });

    rep (i, Z) {
        res.push_back(a.back()[2]);
        a.pop_back();
    }

    sort(all(res));
    for (auto x : res) {
        cout << x << endl;
    }


}