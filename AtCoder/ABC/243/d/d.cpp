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
using ull = unsigned long long;
using namespace std;


signed main() {
    fastio;
    ull n, x;
    string s;
    cin >> n >> x;
    cin >> s;

    stack<char> st;

    for (auto c : s) {
        if (c == 'U') {
            if (st.size() and st.top() != 'U') st.pop();
            else st.push(c);
        }
        else {
            st.push(c);
        }
    }
    s = "";
    while (st.size()) {
        s += st.top(); st.pop();
    }
    reverse(all(s));
    for (auto c : s) {
        if (c == 'U') {
            x >>= 1;
        }
        if (c == 'R') {
            x <<= 1;
            x++;
        }
        if (c == 'L') {
            x <<= 1;
        }
    }
    cout << x << endl;
    return 0;
}