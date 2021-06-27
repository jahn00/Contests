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
    int n; cin >> n;
    unordered_map<string, std::array<int, 2>> mp; //
    rep(_, n) {
        string s; cin >> s;
        if (s[0] == '!') {
            mp[s.substr(1)][1] = 1;
        }
        else {
            mp[s][0] = 1;
        }
    }

    for (auto& p : mp) {
        string s = p.first;
        int l = p.second[0], r = p.second[1];
        if (l and r) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}