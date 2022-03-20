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
    int Q; cin >> Q;
    vector<array<int, 3>> queries(Q);

    rep(q, Q) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            queries[q] = {1, x, 0};
        }
        if (t == 2) {
            int k; cin >> k;
            queries[q] = {2, x, k};
        }
        if (t == 3) {
            int k; cin >> k;
            queries[q] = {3, x, k};
        }
    }

    multiset<int> mp;
    for (auto& q : queries) {
        int t = q[0];
        int x = q[1];
        int k = q[2];
        if (t == 1) {
            // insert
            mp.insert(x);
        }
        else if (t == 2) {
            // all elements less than or equal to x
            auto it = mp.upper_bound(x);
            while (it != mp.begin() and k) {
                k--; it--;
            }
            if (k > 0) {
                cout << -1 << endl;
            }
            else {
                cout << *it << endl;
            }
        }
        else if (t == 3) {
            // greater than or equal to x
            auto it = mp.lower_bound(x);
            k--;
            while (it != mp.end() and k) {
                k--; it++;
            }
            if (it == mp.end()) {
                cout << -1 << endl;
            }
            else {
                cout << *it << endl;
            }
        }
    }
}