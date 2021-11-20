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

const int mxn = 15;
int N;
string s;
int d[mxn + 1][(1 << 15) + 1][2];

int f(int idx, int mask, int flag) {
    //cout << idx << " " << mask << " " << flag << endl;
    if (idx == s.size()) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mask & (1 << i)) {
                while (i < s.size() and (mask & (1 << i))) {i++; cnt++;}
                return cnt;
            }
        }
        return cnt;
    }
    int& res = d[idx][mask][flag];
    if (~res) return res;
    res = 0;
    int cur = s[idx] - '0';
    int upper = flag ? cur : 9;
    for (int i = 0; i <= upper; i++) {
        int nmask = i == 1 ? (mask | (1 << idx)) : mask;
        res += f(idx + 1, nmask, (flag and i == upper) ? 1 : 0);
    }
    return res;
}

signed main() {
    fastio;
    cin >> N;
    s = to_string(N);
    memset(d, -1, sizeof d);
    cout << f(0, 0, 1) << endl;
}