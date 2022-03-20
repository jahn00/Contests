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

struct P {
    int val, cnt;
    P(int a, int b): val(a), cnt(b) {};
};

signed main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    stack<P> st; // (val, cnt)
    int res = 0;
    for (auto& ai : a) {
        if (st.empty() or st.top().val != ai) {
            st.emplace(ai, 1);
        }
        else {
            st.top().cnt++;
        }
        res++;
        // make the pops if possible
        if (st.top().cnt == st.top().val) {
            res -= st.top().cnt;
            st.pop();
        }
        cout << res << endl;
    }
    return 0;

}