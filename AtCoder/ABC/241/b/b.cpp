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
#define rep(i,r) for(int i = 0; i < r; i++)
#define per(i,r) for(int i = r; i >= 0; i--)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int,int> mp;
    rep(i, n) {
        int x; cin >> x;
        mp[x]++;
    }
    rep(i, m) {
        int x;
        cin >> x;
        if (mp.count(x)) {
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}