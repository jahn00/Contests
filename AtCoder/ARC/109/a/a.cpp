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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == b) {
        cout << x << endl;
        return 0;
    }
    if (a > b) {
        int d = (a - b);
        cout << min(x*(2*d-1), (a-b-1)*y+x) << endl;
        return 0;
    } else {
        int d = (b - a);
        cout << min(x*(2*d+1), d*y+x) << endl;
        return 0;
    }
    return 0;
}