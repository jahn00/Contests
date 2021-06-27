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
    int cap, Q, T;
    cin >> cap >> Q >> T;
    int res = cap;
    int start = 0, end = 0;
    rep(_, Q) {
        int nstart;
        cin >> nstart;
        int diff = nstart - end;
        res -= diff;
        if (res <= 0) {
            cout << "No" << endl;
            return 0;
        }
        cin >> end;
        res = min(cap, res + end - nstart);
    }
    int diff = T - end;
    res -= diff;
    if (res <= 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}