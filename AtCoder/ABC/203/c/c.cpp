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

int n, k;
signed main() {
    fastio;
    cin >> n >> k;
    map<int, int> mp; // village, coins
    rep(i, n) {
        int ai, bi;
        cin >> ai >> bi;
        mp[ai] += bi;
    }
    int res = 0;
    for (auto& p : mp) {
        int ai = p.first, bi = p.second;
        if (k >= (ai - res)) {
            k -= (ai - res);
            res = ai;
            k += bi;
        }
        else break;
    }
    if (k) {
        res += k;
    }
    cout << res << endl;
}