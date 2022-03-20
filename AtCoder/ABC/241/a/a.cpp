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
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;


const int md = 1e9 + 7;
const int mxn = 55;

int fact[mxn + 1], ifact[mxn + 1];

int mdpow(int b, int e) {
    long long res = 1, B = b;

    while (e) {
        if (e % 2) {
            res *= B;
            res %= md;
        }
        //cout << B << endl;
        B *= B;
        B %= md;
        e >>= 1;
    }
    return res;
}

void do_fact() {
    memset(fact, 0, sizeof(fact));
    memset(ifact, 0, sizeof(ifact));
    fact[0] = 1;
    for (int i = 0; i < mxn; i++) {
        fact[i + 1] = (1LL * fact[i] * (i + 1)) % md;
    }

    ifact[mxn] = mdpow(fact[mxn], md - 2);
    for (int i = mxn; i >= 1; i--) {
        ifact[i - 1] = (1LL * ifact[i] * (i)) % md;
    }

}

int bi(int n, int k) {
    if (k > n) return 0;
    return (((1LL * fact[n] * ifact[n - k]) % md) * ifact[k] % md);
}

int main(){
    long long n = 1e6;
    long long squares = 0, cubes = 0;
    for (long long i = 1; i <= n; i++) {
        if (i * i <= n) {
            squares++;
        }
        if (i * i * i <= 1e6) {
            cubes++;
        }
    }
    cout << "squares: " << squares << endl;
    cout << "cubes: " << cubes << endl;

    return 0;
}