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

const int mn = 31;
char m[mn][mn];

signed main() {
    fastio;
    int h, t;
    cin >> h >> t;
    rep(r, h) {
        rep(c, h) {
            if (c < t)
                m[r][c] = '#';
            else {
                m[r][c] = '.';
            }
        }
    }

    for (int r = h-1; ~r; r--) {
        if (r >= h - t) {
            rep(c, h) {
                m[r][c] = '#';
            }
        }
    }
    rep(i,h) {
        rep(j,h) {
            cout << m[i][j];
        }
        cout << endl;
    }
}