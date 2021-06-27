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
#define nl '\n'
using namespace std;

const int mn = 1e5 + 10;
int n;
int A[mn], B[mn], C[mn];

signed main() {
    fastio;
    cin >> n;
    memset(A, 0, sizeof(int) * n);
    memset(B, 0, sizeof(int) * n);
    memset(C, 0, sizeof(int) * n);
    rep(i, n) {
        int ai; cin >> ai; ai--;
        A[ai]++;
    }
    rep(i, n) cin >> B[i], --B[i];
    rep(i, n) cin >> C[i], --C[i];
    int res = 0;
    rep(j, n) {
        res += A[B[C[j]]];
    }
    cout << res << endl;
}