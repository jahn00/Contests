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
#define nl '\n'
using namespace std;

signed main() {
    fastio;
    int n; cin >> n;
    /*
    find the first tri# that exceeds n
    */
    int l = 0, r = 1e5;
    while (l < r) {
	    int mid = l + (r - l) / 2;
	    int tri = mid*(mid + 1)/2;
	    if (tri < n) {
		    l = mid + 1;
	    }
	    else {
		    r = mid;
	    }
    }
    cout << l << endl;
}