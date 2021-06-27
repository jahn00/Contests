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

const int mn = 1e3 + 10;
int R, C;
int g[mn][mn];
int f[mn][mn]; // fewest number of magic to arrive at f[r][c]
int dir[5] =  {-1, 0, 1, 0, -1};
int sr, sc, tr, tc;
int inf = 0x3f3f3f3f3f3f3f3f;

int dfs(int r, int c) {
    int& res = f[r][c];
    if (~res) return res;
    res = inf;
    rep(i, 4) {
        int dr = r + dir[i], dc = c + dir[i + 1];
        if (dr < 0 || dr >= R || dc < 0 || dc >= C || !g[dr][dc]) continue;
        res = min(res, dfs(dr, dc));
    }
    for (int i = 0; i < 5/2; i++) {
        for (int j = 0; j < 5/2; j++) {
            if (!i && !j) continue;
            int dr = r + i, dc = c + j;
            if (dr < 0 || dr >= R || dc < 0 || dc >= C || !g[dr][dc]) continue;
            res = min(res, dfs(dr, dc) + 1);
        }
    }
    return res;
}

signed main() {
    fastio;
    cin >> R >> C;
    cin >> sr >> sc >> tr >> tc;
    sr--, sc--, tr--, tc--;

    memset(g, 0, sizeof g);
    rep(r, R) {
        rep(c, C) {
            char grc;
            cin >> grc;
            if (grc == '.') {
                g[r][c] = 1;
            }
        }
    }
    memset(f, -1, sizeof f);
    f[tr][tc] = 0;
    int res = dfs(sr, sc);
    if (res == inf) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}