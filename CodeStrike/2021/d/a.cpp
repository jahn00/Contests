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
int a[mn];

signed main() {
    fastio;
    int n, N;
    cin >> n >> N;
    unordered_map<int, int> mp;
    rep(i, n) {
        cin >> a[i];
        if (i < N) {
            mp[a[i]]++;
        }
    }
    for (int i = N, j = 0; i < n; j++, i++) {
        int aj = a[j];
        int ai = a[i];
        bool found = false;
        for (auto& [x, cnt] : mp) {
            if(mp.count(ai - x)) {
                if (ai == 2*x and mp[ai-x] < 2) {
                    continue;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << ai << endl;
            return 0;
        }
        mp[aj]--;
        mp[ai]++;
    }
    assert(false);
}