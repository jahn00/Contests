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

int n;

signed main() {
    fastio;
    cin >> n;
    vector<double> distance(n), speed(n), time(n);
    double total_time = 0;
    rep(i, n) {
        cin >> distance[i]; cin >> speed[i];
        time[i] = distance[i] / speed[i];
        total_time += time[i];
    }

    double half_time = total_time / 2;
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (time[i] > half_time) {
            res += half_time * speed[i];
            cout << setprecision(10) << res << endl;
            return 0;
        }
        else {
            half_time -= time[i];
            res += distance[i];
        }
    }
    return 0;
}