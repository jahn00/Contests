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

int to_oct(int x) {
   int octalNum = 0, placeValue = 1;
   int dNo = x;
   while (x != 0) {
      octalNum += (x % 8) * placeValue;
      x /= 8;
      placeValue *= 10;
   }
   return octalNum;
}

bool bad(int x) {
    while (x) {
        if (x % 10 == 7) {
            return true;
        }
        x /= 10;
    }
    return false;
}

void dfs(set<int>& st, int val) {
    if (val > n) return;

    if (bad(to_oct(val))) {
        st.insert(val);
    }

    for (int i = 0; i < 10; i++) {
        int nval = val * 10 + i;
        dfs(st, nval);
    }
}

signed main() {
    fastio;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k) {
            if (k % 10 == 7) {
                st.insert(i);
                break;
            }
            k /= 10;
        }
    }
    for (int i = 1; i < 10; i++) {
        dfs(st, i);
    }
    cout << n - st.size() << endl;
}