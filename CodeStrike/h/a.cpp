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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b == 0 and d == 0) {
        cout << a << endl;
        return 0;
    }
    if (a >= c) {
        cout << a << endl;
        return 0;
    }
    int turn = 1;
    while (true) {
        if (turn) {
            if (a + b >= c) {
                cout << c << endl;
                return 0;
            }
            a += b;
        }
        else {
            if (c - d <= a) {
                cout << a << endl;
                return 0;
            }
            c -= d;
        }
        turn ^= 1;
    }
    return 0;
}