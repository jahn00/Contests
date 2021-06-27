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
    uint n, A = 0, B = 0; cin >> n;
    vector<std::array<int, 3>> v;
    rep(_, n) {
        int a, b;
        cin >> a >> b;
        A += a;
        v.push_back({2*a + b, a, b});
    }
    sort(all(v));
    reverse(all(v));

    uint res = 0;
    for (int i = 0; i < n; i++) {
        if (B > A) break;
        B += (v[i][1] + v[i][2]);
        A -= v[i][1];
        res++;
    }
    cout << res << endl;
}