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

string s;

bool ispali(string s) {
    int n = s.size();
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        if (s[l] != s[r]) return false;
    }
    return true;
}

signed main() {
    fastio;
    cin >> s;
    int n;
    n = s.size();

    if (ispali(s)) {
        cout <<  "Yes" << endl;
        return 0;
    }
    int i = 0, j = n - 1;
    int lcount = 0, rcount = 0; // count of a's from left and right
    while (j >= 0 and s[j] == 'a') {
        rcount++;
        j--;
    }
    while (i < n and s[i] == 'a') {
        lcount++;
        i++;
    }
    string sub = s.substr(i, j - i + 1);
    bool good = ispali(sub);

    if (lcount > rcount) {
        cout << "No" << endl;
        return 0;
    }
    else if (ispali(sub)) {
        cout << "Yes" << endl;
        return 0;
    }
    else {
        cout << "No" << endl;
        return 0;
    }

    // maybe
    return 0;

}