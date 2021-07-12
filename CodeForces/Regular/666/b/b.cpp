#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>
#include <bitset>
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

const int mn = 1e5 + 2;
int n;
int a[mn], save[mn];
const int inf = 0x3f3f3f3f;

uint poww(uint b, int e) {
    uint res = 1;
    uint mul = 1;
    while (e) {
        if (e & 1) {
            res *= mul;
        }
        mul *= b;
        e >>= 1;
    }
    return res;
}

// counts the cost of using c as the base
uint f(int c) {
    int& res = save[c];
    if (~res) return res;
    res = 0;
    for (int i = 0; i < n; i++)  {
        int ai = a[i];
        int ci = poww(c, i);
        res += abs(ci - ai);
    }
    return res;
}

signed main() {
    fastio;
    cin >> n;
    memset(save, -1, sizeof save);
    rep (i, n) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    sort (a, a + n);
    int l = -1; int r = (int) pow(a[n-1], 1.0 / (n-1));
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        // cerr << f(mid) << endl;
        if (f(mid) <= f(mid + 1)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    // cout << "l + 1: " << l + 1 << endl;
    cout << f(l + 1) << endl;
}