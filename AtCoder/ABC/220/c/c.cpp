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
int tot;
vector<int> a;

int f(int idx) {
    // f is a magic func that computes the sum up to idx i
    int remainder = idx % n;
    int res = idx / n * tot;
    for (int i = 0; i < remainder; i++) res += a[i];
    return res;
}

signed main() {
    fastio;
    cin >> n;
    a.assign(n + 1, 0);
    rep(i, n) cin >> a[i];
    tot = accumulate(all(a), 0LL);
    //print(tot);

    int x; cin >> x;
    int l = 1, r = (x + tot - 1) / tot * n + 10;
    while (l < r) {
        int idx = l + (r - l) / 2;

        int sum = f(idx);
        if (sum > x) {
            r = idx;
        }
        else l = idx + 1;
    }
    cout << l << endl;
}