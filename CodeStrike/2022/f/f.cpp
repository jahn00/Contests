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


bool is_possible(const array<int, 3>& a) {
    int l = a[0], r = a[1], any = a[2];
    if (!l and r and !any) {
        return false;
    }
    else if (l and !r and !any) {
        return false;
    }
    else if (l == 0 and r == 0) {
        if (any < 2) return false;
    }
    return true;
}


signed main() {
    fastio;
    int n; cin >> n;
    unordered_map<string, array<int, 3>> mp;
    rep(_, n) {
        string brand, hand;
        int count;
        cin >> brand >> hand >> count;
        if (hand == "left") {
            mp[brand][0] = count;
        }
        else if (hand == "right") {
            mp[brand][1] = count;
        }
        else if (hand == "any") {
            mp[brand][2] = count;
        }
    }

    int res = 0;
    int possible = 0;
    for (auto& p : mp) {
        auto a = p.second;
        //cout << p.first << " " << a[0] << " " << a[1] << " " << a[2] << endl;
        int l = a[0], r = a[1];
        possible += is_possible(a);
        res += max(l, max(r, 1LL));
    }
    if (possible == 0) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << res + 1 << endl;
}