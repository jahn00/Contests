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

int R, C;
vector<vector<int>> m, visited;

vector<int> dir = {-1, 0, 1, 0, -1};

void dfs(int r, int c) {
    visited[r][c] = 1;
    m[r][c] = 2;
    for (int i = 0; i < 4; i++) {
        int dr = r + dir[i];
        int dc = c + dir[i + 1];
        if (dr < 0 or dr >= R or dc < 0 or dc >= C or visited[dr][dc] or m[dr][dc] == 0) continue;
        dfs(dr, dc);
    }
    return;

}

signed main() {
    fastio;
    cin >> R >> C;
    m.resize(R, vector<int>(C));
    rep(r, R) {
        string row;
        cin >> row;
        rep(c, C) m[r][c] = row[c]- '0';
    }
    visited.assign(R, vector<int>(C, 0));

    rep(r, R) {
        if (m[r][0] == 0 or visited[r][0]) continue;
        dfs(r, 0);
    }
    rep(r, R) {
        if (m[r][C - 1] == 0 or visited[r][C-1]) continue;
        dfs(r, C-1);
    }
    rep(c, C) {
        if (m[0][c] == 0 or visited[0][c]) continue;
        dfs(0, c);
    }
    rep(c, C) {
        if (m[R - 1][c] == 0 or visited[R - 1][c]) continue;
        dfs(R - 1, c);
    }
    //cout << endl;
    rep(r, R) {
        rep(c, C) {
            if (m[r][c] == 1 or m[r][c] == 0) {
                cout << 0;
                continue;
            }
            else cout << 1;
        }
        cout << endl;
    }
}