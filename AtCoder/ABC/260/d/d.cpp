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
    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    rep (i, n) {
        cin >> cards[i];
    }
    if (k == 1) {
        for (auto x : cards)
            cout << x << endl;
        return 0;
    }

    vector<int> res(n + 1, -1);
    vector<vector<int>> mp;
    for (int move = 0; move < n; move++) {
        int card = cards[move];

        auto it = lower_bound(all(mp), vector<int> {card}, [&](const vector<int>& lhs, const vector<int>& rhs){
            return lhs.back() < rhs.back();
        });


        if (it == mp.end()) {
            //cout << card << endl;
            mp.push_back({card});
            continue;
        }

        it->push_back(card);

        if (it->size() == k) {
            for (auto x : *it) {
                res[x] = move + 1;
            }

            it->push_back(-inf);
        }

    }

    for (auto v : mp) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
}