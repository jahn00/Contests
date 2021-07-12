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
#include <array>
#include <bitset>
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;

const int mn = 1e5+10;
int pre[mn], nw[mn];

signed main() {
    fastio;
    int tt; cin >> tt;
    while(tt--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        vector<int> pre(n+1, 0), nw(n+1, 0);
        char prev = 'L';
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i];
            nw[i+1] = nw[i];
            char c = s[i];
            if (c == 'W') {
                nw[i+1]++;
                pre[i+1] += prev == 'W' ? 2 : 1;
                prev = 'W';
            }
            else {
                prev = 'L';
            }
        }
        int wind = min(n, nw[n] + k);

        int res = 0;
        for (int i = 0, j = wind; j <= n; i++, j++) {
            int score = pre[j] - pre[i];
            int w = (nw[j] - nw[i]);
            int nl = wind - w;
            int nscore;
            if (w) {
                int new_w = w + min(nl, k);
                nscore = new_w*2-1;
            }
            else {
                int new_w = min(nl, k);
                nscore = new_w*2-1;
            }

            res = max(res, nscore);
        }
        cout << res << endl;
    }
}