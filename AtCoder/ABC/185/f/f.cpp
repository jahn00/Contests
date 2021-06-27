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


vector<int> a;
struct Segtree {
    int n;
    vector<int> seg;
    Segtree(int n) {
        this->n = n;
        seg.resize(2*n);
        for (int i = 0; i < n; i++) {
            seg[i + n] = a[i];
        }

        for (int i = n - 1; i > 0; i--) {
            seg[i] = seg[i << 1] ^ seg[(i << 1) | 1];
        }
    }

    void update(int p, int val) {
        p += n;
        seg[p] ^= val;

        for (; p > 1; p >>= 1) {
            seg[p >> 1] = seg[p] ^ seg[p ^ 1];
        }
    }

    int get(int l, int r) {
        int res = 0;
        l += n; r += n;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l % 2) res ^= seg[l++];
            if (r % 2) res ^= seg[--r];
        }
        return res;
    }
};

signed main() {
    fastio;
    int n, Q; cin >> n >> Q;
    a.resize(n);
    rep(i, n) {
        cin >> a[i];
    }
    Segtree seg(n);

    rep (q, Q) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            // update xth element with y
            seg.update(x, y);
        } else {
            // xor sum on interval [x, y]
            y--;
            int get = seg.get(x, y + 1);
            cout << get << endl;
        }
    }
    return 0;
}