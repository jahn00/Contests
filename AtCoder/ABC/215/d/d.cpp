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
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbgarr(x, sz)                                             \
    for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
    cout << endl;
#define dbgarr2(x, __rows, __cols)                \
    for (int asdf2 = 0; asdf2 < __rows; asdf2++) { \
        dbgarr(x[asdf2], __cols);                   \
    }
#define dbgstd(x)                                                           \
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

const int mxn = 1e5 + 5;
int sieve[mxn];


vector<int> f(int x) {
    vector<int> prime_factors;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        prime_factors.push_back(i);
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x > 2) prime_factors.push_back(x);
    return prime_factors;
}

signed main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<int> a(N), primes;
    rep(i, N) cin >> a[i];
    vector<int> line(M + 1);
    unordered_set<int> used_primes;
    for (auto& ai : a) {

        auto prime_factors = f(ai);

        for (auto& p : prime_factors) {
            if (used_primes.count(p)) continue;

            for (int j = p; j <= M; j += p) {
                line[j] = 1;
            }

            used_primes.emplace(p);
        }
    }
    // cout << "USED PRIMES" << nl;
    // dbgstd(used_primes);

    cout << M - accumulate(all(line), 0) << nl; for (int i = 1; i <= M; i++) if(!line[i]) cout << i << nl;
}