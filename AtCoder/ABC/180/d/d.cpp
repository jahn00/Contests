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

bool is_over(uint a, uint b) {
    if (!a or !b)  return false;
    uint res = a*b;
    if (res / b == a) return false;
    if (res / a == b) return false;
    return true;
}

signed main() {
    fastio;
    uint x,y,a,b,res=0;
    cin >> x >> y >> a >> b;
    while (1) {
        if (a >= y/x) break;
        if (x*a >= x+b) break;
        res++;
        x *= a;
    }
    res += (y-1-x)/b;
    cout << res << endl;
}