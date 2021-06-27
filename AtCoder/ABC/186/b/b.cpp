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

signed main() {
    fastio;
    int R, C;
    cin >> R >> C;
    vector<vector<int>> m(R, vector<int>(C));
    int mini = inf;
    rep (r, R) {
        rep (c, C) {
            cin >> m[r][c];
            mini = min(m[r][c], mini);
        }
    }
    int res = 0;
    rep (r, R) {
        rep (c, C) {
            res += (m[r][c] - mini);
        }
    }
    cout << res << endl;
}