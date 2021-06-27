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
#define nl '\n'
using namespace std;

set<int> res;
vector<set<int>> grid;
int R;
void dfs(int r, int c) {
    if (r == R - 1) {
        res.emplace(c);
        return;
    }
    //cout << r << " " << c << endl;
    if (grid[r + 1].count(c + 1)) {
        dfs(r + 1, c + 1);
    }
    if (grid[r + 1].count(c - 1)) {
        dfs(r + 1, c - 1);
    }
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;;
    vector<pair<int,int>> a;

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    
    sort(all(a));
    R = 1;
    // row-wise compression
    for (int i = 0; i < m; i++) {
        int last_row = a[i].first;
        a[i].first = R;
        int j = i + 1;
        while (j < n and a[j].first == last_row) {
            a[j].first = R;
            j++;
        }
        R++;
        i = j - 1;
    }
    // R now holds total number of unique rows [0, R)
    grid.assign(R + 1, set<int>());
    for (int i = 0; i < m; i++) {
        grid[a[i].first].emplace(a[i].second);
    }
    cout << endl;
    int i =0;
    for (auto r : grid) {
        cout << i << " ";
        for (auto c : r) {
            cout << c << " ";
        }
        i++;
        cout << endl;
    }
    dfs(0, n);
    cout << res.size() << endl;
}