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
// HEIGHT
// 2147483647

signed main() {
    fastio;
    int maxi = 1;
    int sum = 0;
    rep(i,6) {
        int h; cin >> h;
        sum += h;
        maxi = max(maxi, h);
    }
    int target = (7 - sum % 7);
    int start = (maxi / 7) * 7;
    while (true) {
        if (((start + target + sum) % 7) == 0) {
            cout << start + target << endl;
            return 0;
        }
        start += 7;
    }


    return 0;
}