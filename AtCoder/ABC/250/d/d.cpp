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
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;


signed main() {
    fastio;
    long long N; cin >> N;

    long long mxn = pow(N, 1.0 / 3) + 10;
    vector<long long> lp(mxn + 1);
    vector<long long> pr;

    for (long long i = 2; i <= mxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (long long j = 0; j < (long long)pr.size() && pr[j] <= lp[i] && (i*pr[j]) <= mxn; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    int n = pr.size();
    int res = 0;
    for (int i = 0; pr[i] < n; i++) {
        long long p = 1LL * pr[i];
        for (int j = i + 1; j < n; j++) {
            long long q = 1LL * pr[j];
            if (q * q * q <= N / p) {
                //cout << p << "," << q << endl;
                res++;
            }
            else break;
        }
    }
    cout << res << endl;
    // 1e18
    // 1000000000000000000

    return 0;

}