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
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

const int mn = 3e3 + 10;
int n;

int solve(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int i3 = i + 1; i3 < n; i3++) {
            int i2 = lower_bound(b.begin(), b.end(), i3) - b.begin() - 1;
            int i4 = upper_bound(b.begin(), b.end(), i3) - b.begin();
            cerr << i << " " << i2 << " " << i3 << " " << i4 << endl;
            if (i < i2 and i2 < i3 and i3 < i4) res++;
            else continue;
        }
    }
    return res;
}

signed main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        cin >> n;
        unordered_map<int, vector<int>> mp; // val -> list of indices
        rep (i, n) {
            int ai;
            cin >> ai;
            mp[ai].push_back(i);
        }

        int res = 0;
        for (auto p : mp) {
            for (auto p2 : mp) {
                if (p.first == p2.first) break;
                res += solve(p.second, p2.second);
            }
        }
        cout << res << endl;
    }
}