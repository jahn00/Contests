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
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

signed main() {
	fastio;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	const int big = 1e5 + 1231;
	int l = 0, r = big;

	while (l < r) {
		int m = l + (r - l) / 2;

		int cyan = a + b * m;
		int red = d * c * m;
		//cout << cyan << " " << red << endl;

		if (cyan <= red) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	if (l == big) {cout << -1 << endl; return 0; }
	cout << l << endl;
}