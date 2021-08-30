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

signed main() {
    fastio;
    int n; cin >> n;
    unordered_set<string> st;
    rep(i, n) {
        string s, t;
        cin >> s >> t;
        string u = s + "+" + t;
        if (st.count(u)) {
            cout << "Yes" << endl;
            return 0;
        }
        st.emplace(u);
    }
    cout << "No" << endl; return 0;
}