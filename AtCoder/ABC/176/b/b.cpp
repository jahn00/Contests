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
#include <bitset>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

signed main() {
    fastio;
    string n;
    cin >> n;
    int len = n.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += n[i] - '0';
        if (res >= 9) res -= 9;
    }
    if (res == 0) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}