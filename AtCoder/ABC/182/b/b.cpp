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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = 1, maxi = 0;
    for (int k = 2; k <= *max_element(all(a)); k++) {
        int cnt = 0;
        for (auto& ai : a) {
            if (ai % k == 0) cnt++;
        }
        if (cnt > maxi) {
            maxi = cnt;
            res =  k;
        }
    }
    cout << res << endl;
}