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

bool f(pair<int,int>& a, pair<int,int>& b) {
    return (a.first*b.second - a.second*b.first) == 0;
}

signed main() {
    fastio;
    int n; cin >> n;
    vector<pair<int,int>> a;
    rep (i, n) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int,int> aj((a[j].first - a[i].first), (a[j].second - a[i].second));
            for (int k = j + 1; k < n; k++) {
                pair<int,int> ai((a[k].first - a[i].first), (a[k].second - a[i].second));
                if (f(ai, aj)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;

}