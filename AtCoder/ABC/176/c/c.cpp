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
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

const int mn = 2e5 + 10;
int a[mn], b[mn];

signed main() {
    fastio;
    int n;
    cin >> n;
    int maxi = 0, res = 0;
    rep(i, n) {
        cin >> a[i];
        int ai = a[i];
        maxi = max(maxi, ai);
        if (ai < maxi) {
            res += maxi - ai;
        }
    }
    cout << res << endl;
}