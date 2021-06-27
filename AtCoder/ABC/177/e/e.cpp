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
#define endl '\n'
using namespace std;

const int mn = 1e6 + 10;
int n;
int a[mn];

int gcd(int a, int b) {
    return a % b ? gcd(b , a % b) : b;
}

signed main() {
    fastio;
    cin >> n;
    rep (i, n) {
        cin >> a[i];
    }

    set<int> st, temp; // set of all factors
    int g = a[0];
    bool pairwise = true;
    for (int i = 0; i < n; i++) {
        int ai = a[i];
        // check for setwise coprime
        if (i > 0)
            g = gcd(g, ai);

        if (pairwise) {
            // factorize ai
            for (int i = 2; i * i <= ai; i++) {
                if (ai % i == 0) {
                    temp.insert(i);
                }
                while (ai % i == 0)
                    ai /= i;
            }

            if (ai != 1) temp.insert(ai);
            for (auto& t : temp) {
                if (st.count(t)) {
                    pairwise = false;
                }
                else st.insert(t);
            }
        }
        temp.clear();
    }

    if (pairwise) {
        cout << "pairwise coprime" << endl;
    }
    else if (g == 1) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }
}