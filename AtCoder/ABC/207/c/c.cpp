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

map<int, int> table[5];

signed main() {
	fastio;
	int n; cin >> n;
	rep(i, n) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			// [,]
			table[1][l] += 1;
			table[1][l + 1] -= 1;
		}
		if (t == 2) {
			// [,)
			table[2][l] += 1;
			table[2][l] -= 1;
		}
		if (t == 3) {
			// (,]
			table[3][l + 1] += 1;
			table[3][l + 1] -= 1;
		}
		if (t == 4) {
			// (,) 
			table[4][l + 1] += 1;
			table[4][l] -= 1;
		}
	}

	int res = 0;
	for (int i = 1; i <= 4; i++) {
		map<int, int> mp = table[i];
		for (int j = i + 1; j <= 4; j++) {
			for (auto& p : table[j]) {
				// merge the two intervals
				mp[p.first] += p.second;
			}
			int sum = 0;
			for (auto& p : mp) {
				sum += p.second;
				cout << sum << " ";
				res += sum >= 2;
			}
			cout << endl;
		}
	}
	cout << res << endl;
	return 0;

}