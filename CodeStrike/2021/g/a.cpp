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
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre(n + 1), suf(n +1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == 'c');
    }
    for (int i = n-1; ~i; i--) {
        suf[i] = suf[i + 1] + (s[i] == 'c');
    }
    if (pre[n] % 2) {
        cout << 0 << endl;
        return;
    }
    if (pre[n] == 0) {
        cout << 1 << endl;
        return;
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        if (pre[i] == suf[i] and s[i-1] == '.') res++;
    }
    cout << res + 1 << endl;
}

signed main() {
    fastio;
    int T;
    cin >> T;
    cout << T << endl;
    while (T--) {
        solve();
    }
}