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
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbgarr(x, sz)                                             \
    for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
    cout << endl;
#define dbgarr2(x, __rows, __cols)                \
    for (int asdf2 = 0; asdf2 < __rows; asdf2++) { \
        dbgarr(x[asdf2], __cols);                   \
    }
#define dbgstd(x)                                                           \
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

signed main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<int> S(N + N), T(M);
    rep(i, N) { cin >> S[i]; S[i + N] = S[i]; }
    rep(i, M) cin >> T[i];

    int s_maxi = *max_element(all(S)), s_mini = *min_element(all(S));
    int t_maxi = *max_element(all(T)), t_mini = *min_element(all(T));

    if (t_maxi == t_mini and t_maxi != s_maxi and t_maxi != s_mini) {
        // if t chars are all the same and s does not have it, fail
        cout << -1 << endl; return 0;
    }
    if (s_maxi == s_mini and t_mini != t_maxi) {
        // if s chars are all the same and t has both
        cout << -1 << endl; return 0;
    }


    int j = N, l = j, r = j;
    while (S[l] == S[j] and S[r] == S[j]) {
        l--; r++;
    }
    int cost = inf; // cost to move from S[N] for the first time to an opposite number
    if (S[l] != S[N]) {
        cost = N - l;
    }
    if (S[r] != S[N]) {
        cost = min(cost, r - N);
    }
    int res = 0;
    bool found = false;
    int point = S[N];
    for (int i = 0; i < M; i++) {
        int ti = T[i];
        if (point != ti) {
            // not the same
            if (!found) {
                res += cost;
                found = true;
            }
            else {
                res++;
            }
        }
        point = ti;
        res++;
    }
    cout << res << endl;
    return 0;

}