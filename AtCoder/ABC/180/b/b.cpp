#include <iostream>
#include <iomanip>
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
#define ld long double
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

signed main() {
    fastio;
    int n;
    cin >> n;
    int man = 0, euc = 0, norm = -1;

    rep(i, n) {
        int ai;
        cin >> ai;
        ai = abs(ai);
        man += ai;
        euc += ai*ai;
        norm = max(norm, ai);
    }

    cout << man << endl;
    cout << setprecision(18) << sqrt(euc) << endl;
    cout << norm << endl;
}