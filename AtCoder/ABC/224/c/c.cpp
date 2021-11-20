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
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

struct P {
    int x;
    int y;

    P(int x, int y): x(x), y(y) {};

    P slope(const P& rhs) const {
        return P(this->x - rhs.x, this->y - rhs.y);
    }

    bool same(const P& rhs) const {
        return this->y * rhs.x == rhs.y * this->x;
    }
};


signed main() {
    fastio;
    int n; cin >> n;
    vector<P> a;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        P ai = a[i];
        for (int j = i + 1; j < n; j++) {
            P aj = a[j];
            for (int k = j + 1; k < n; k++) {
                P ak = a[k];
                P l = ai.slope(aj);
                P r = ai.slope(ak);
                if (l.same(r)) continue;
                else res++;
            }
        }
    }
    cout << res << endl;

}