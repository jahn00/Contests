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
#define int unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

const int mn = 61;
int comb[mn][mn];
int A, B, k;

int C(int _n, int _r) {
    return comb[_n][_r];
}

string f(int a, int b, int k) {
    if (a <= 0) return string(b, 'b');
    if (b <= 0) return string(a, 'a');
    int total = C(a + b - 1, b);
    if (k <= total) {
        return "a" + f(a - 1, b, k);
    }
    else {
        return "b" + f(a, b - 1, k - total);
    }
}

signed main() {
    fastio;
    cin >> A >> B >> k;
    memset(comb, 0, sizeof comb);
    comb[0][0] = 1;
    for (int i = 0; i < mn; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    string res = f(A, B, k);
    cout << res << endl;
}