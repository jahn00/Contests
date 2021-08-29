#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>
#define rep(i, n) for(int _ = 0; _ < (int) n; _++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

signed main() {
    fastio;
    int s, t;
    cin >> s >> t;
    int res = 0;
    for (int i = 0; i <= s; i++) {
        for (int j = 0; i + j <= s; j++) {
            for (int k = 0; i + j + k <= s; k++) {
                if (i * j * k <= t) res++;
            }
        }
    }
    cout << res << endl;
}