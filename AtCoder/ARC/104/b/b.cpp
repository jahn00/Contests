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

signed main() {
    fastio;
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int,int>> pre(n + 1);
    pre[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        char c = s[i];
            pair<int,int> curr = {1, 0};
        if (c == 'A') {
            curr = {1, 0};
        }
        if (c == 'G') {
            curr = {0, 1};
        }
        if (c == 'T') {
            curr = {-1, 0};
        }
        if (c == 'C') {
            curr = {0, -1};
        }
        pre[i + 1].first = pre[i].first + curr.first;
        pre[i + 1].second = pre[i].second + curr.second;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int A = pre[j].first - pre[i].first;
            int G = pre[j].second - pre[i].second;
            // cout << A << " " << G << endl;
            if (!A and !G) {
                // cout << i << " " << j << endl;
                res++;
            }
        }
    }
    cout << res << endl;
}