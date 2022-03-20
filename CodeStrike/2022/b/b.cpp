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


signed main() {
    fastio;
    string s;
    cin >> s;
    int n = s.size();
    if (n < 15 or n > 34) {
        cout << "incorrect" << endl;
    }

    for (auto& c : s) {
        if (isdigit(c) or isupper(c)) continue;
        else cout << "incorrect" << endl;
    }

    // Move the first four characters of the code to the end of the code.
    string first_four = s.substr(0, 4);
    s = s.substr(4) + first_four;
    string ns;
    for (auto& c : s) {
        if (isdigit(c)) {
            ns += c;
        }
        else {
            int dig = c - 'A' + 10;
            ns += to_string(dig);
        }
    }
    int res = 0;
    const int md = 97;
    for (auto& c : ns) {
        int x = c - '0';
        res *= 10;
        res += x;
        res %= md;
    }
    //cout << res << endl;
    if (res == 1)
        cout << "correct" << endl;
    else
        cout << "incorrect" << endl;
}