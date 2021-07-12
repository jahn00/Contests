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

const int mn = 110;
vector<vector<int>> m;
int R, C;

int ccost(vector<int>& row) {
    int cost = 0;
    for (int r = 0, c = C-1; r != c; r++, c--) {
        cost += abs(row[r] - row[c]);
    }
    return cost;
}

int rcost(vector<int>& a, vector<int>& b) {
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--){ 
        cin >> R >> C;
        int sum = 0;

        m.resize(R, vector<int>(C));

        rep (r, R) {
            rep (c, C) {
                cin >> m[r][c];
            }
        }

        int cost = 0;
        for (int top = 0, bot = R-1; top != bot; top++, bot--) {
            int t = ccost(m[top]);
            int b = ccost(m[bot]);
        }        
    return cost;
}