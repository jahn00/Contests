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

    int a, b, c;
    cin >> a >> b >> c;
    int d1 = (b - a), d2 = (c - b);
    if (d1 == d2) {
        cout << 0 << nl;
        return 0;
    }
    else if (d1 < d2) {
        int d = (d2 - d1);
        if (d % 2) {
            cout << d / 2 + 2 << endl;
        }
        else {
            cout << d / 2 << endl;
        }
        return 0;
    }
    else {
        cout << d1 - d2 << endl;
    }
    return 0;
}