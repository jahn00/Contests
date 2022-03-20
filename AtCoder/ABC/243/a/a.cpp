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
    int v, a, b, c;
    cin >> v >> a >> b >> c;
    while (v >= 0) {
        if (v - a < 0) {
            cout << "F" << nl;
            return 0;
        }
        v -= a;
        if (v - b < 0) {
            cout << "M" << nl;
            return 0;
        }
        v -= b;
        if (v - c < 0) {
            cout << "T" << nl;
            return 0;
        }
        v -= c;
    }
    return 0;

}