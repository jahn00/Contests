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
    string n;
    cin >> n;
    int k = n.size();
    vector<int> mod(3, 0);
    int sum = 0;
    for (auto c : n) {
        int a = (c - '0') % 3;
        mod[a]++;
        sum = (sum + a) % 3;
    }

    // cerr << sum << endl;
    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }
    else if (sum == 1) {
        if (mod[1]) {
            if (1 > k - 1) {
                cout << -1 << endl;
                return 0;
            }
            else {
                cout << 1 << endl;
                return 0;
            }
        }
        else if (mod[2] >= 2) {
            if (2 > k - 1) {
                cout << -1 << endl;
                return 0;
            } else {
                cout << 2 << endl;
                return 0;
            }
        }
    }
    else {
        if (mod[2] >= 1) {
            if (1 > k - 1) {
                cout << -1 << endl;
                return 0;
            } else {
                cout << 1 << endl;
                return 0;
            }
        }
        if (mod[1]) {
            if (2 > k - 1) {
                cout << -1 << endl;
                return 0;
            }
            else {
                cout << 2 << endl;
                return 0;
            }
        }

    }
    return 0;
}