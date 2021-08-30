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
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbgarr(x, sz)                                             \
    for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
    cout << endl;
#define dbgarr2(x, __rows, __cols)                \
    for (int asdf2 = 0; asdf2 < __rows; asdf2++) { \
        dbgarr(x[asdf2], __cols);                   \
    }
#define dbgstd(x)                                                           \
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

int n, m;
vector<vector<int>> table;
unordered_map<int, int> mp; // color -> idx
unordered_map<int, std::array<int, 2>> mp2; // color -> {idx, idx2}

void add(int color, int i) {
    if (mp.count(color)) {
        // if the ball exists in the singleton set, remove it and put into 2s
        int idx = mp[color];
        mp.erase(color);
        mp2[color] = {idx, i};
    }
    else {
        mp[color] = i;
    }
}

void process_cylinder(int i) {
    auto& ti = table[i];
    if (ti.size()) {
        // remove the top element
        ti.pop_back();
        if (ti.size()) {
            // put the next element into singleton map
            int ncolor = ti.back();
            add(ncolor, i);
        }
    }
}

signed main() {
    fastio;
    cin >> n >> m;
    table.assign(m, vector<int>());
    rep(_, m) {
        int k; cin >> k;
        vector<int> cylinder(k);
        rep(i, k) {
            cin >> cylinder[k - i - 1];
        }
        table[_] = cylinder;
    }
    // for (int i = 0; i < m; i++) {
    //     dbgstd(table[i]);
    // }

    for (int i = 0; i < m; i++) {
        int color = table[i].back();
        add(color, i);
    }

    while (mp2.size()) {
        auto top = *mp2.begin();
        int color = top.first; int i = top.second[0], j = top.second[1];

        //cout << i << " " << j << endl;
        process_cylinder(i);
        process_cylinder(j);

        mp2.erase(color);
        n--;
    }

    // cout << "singles" << endl;
    // for (auto x : mp) {
    //     cout << x.first << ": " << x.second << endl;
    // }
    // cout << "doubles" << endl;
    // for (auto x : mp2) {
    //     cout << x.first << ": "; dbgstd(x.second);
    // }
    // dbg(n);

    // if the doubles are empty but there are still balls in the table, impossible
    if (n) {
        cout << "No" << endl;
        return 0;
    }
    else {
        cout << "Yes" << endl;
        return 0;
    }
}
