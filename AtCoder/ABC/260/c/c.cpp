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
#define print(x) cout << (#x) << " is " << (x) << endl;
#define printstd(x)                                                           \
    for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
    cout << endl;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;

using ll = long long;


int n, x, y;

const int RED = 0;
const int BLU = 1;


signed main() {
    fastio;
    cin >> n >> x >> y;

    // quantity, rank, color
    function<ll(ll, int, int)> f = [&](ll count, int rank, int color) {
        if (rank == 1) {
            if (color == BLU) {
                return 1LL * count;
            }
            else return 0LL;
        }
        ll lsum = 0, rsum = 0;
        if (color == RED) {
            ll reds = f(count, rank - 1, RED);
            ll blus = f(x * count, rank, BLU);
            lsum = reds + blus;
        }

        if (color == BLU) {
            ll reds = f(count, rank - 1, RED);
            ll blus = f(y * count, rank - 1, BLU);
            rsum = reds + blus;
        }

        return max(lsum, rsum);

    };

    cout << f(1LL, n, RED) << endl;

}