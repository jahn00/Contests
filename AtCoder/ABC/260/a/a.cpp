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
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;

signed main() {
    fastio;
    string s;
    cin >> s;
    vector<int> mp(26);
    mp[s[0] - 'a']++;
    mp[s[1] - 'a']++;
    mp[s[2] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (mp[i] == 1) {
            cout << char(i + 'a') << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}