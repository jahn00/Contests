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
#include <bitset>
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

signed main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        string res;
        rep (i, n) res += '0';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j] = ((res[j] - '0') | (s[i + j] - '0')) + '0';
            }
        }
        cout << res << endl;
    }
}