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

int n;

struct point {
    int x, y;
    point(int a, int b) {
        this->x = a;
        this->y = b;
    }
};

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b): b;
}

pair<int,int> f(const point& lhs, const point& rhs) {
    pair<int,int> res; // slope, first = dy, second = dx
    res.first = rhs.y - lhs.y;
    res.second = rhs.x - lhs.x;
    int g = gcd(res.first, res.second);
    res.first /= g;
    res.second /= g;
    return res;
}

signed main() {
    fastio;
    cin >> n;
    vector<point> a;
    rep(_, n) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }

    int res = 0;
    for (int j = 0; j < n; j++) {
        point lhs = a[j];
        for (int i = 0; i < j; i++) {
            point rhs = a[i];
            auto m = f(lhs, rhs);
            if (abs(m.first) <= abs(m.second)) res++;
        }
    }
    cout << res << endl;
}