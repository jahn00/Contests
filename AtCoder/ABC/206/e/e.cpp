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
#define debug(x) cout << (#x) << " is " << (x) << endl;
#define dbgarr(x, sz)                                             \
	for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
	cout << endl;
#define dbgarr2(x, __rows, __cols)                \
	for (int asdf2 = 0; asdf2 < __rows; asdf2++) { \
		dbgarr(x[asdf2], __cols);                   \
	}
#define dbgstd(x)                                                           \
	for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
	cout << endl;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;


int L, R;
//const int MAXI = 1e6 + 10;
vector<vector<int>> binom;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

void pascals() {
	binom.assign(L + 1, vector<int>(L + 1, 0));

	for (int i = 1; i <= L; i++) {
		binom[i][0] = binom[i][i] = 1;
		for (int j = 1; j + 1 <= L; j++) {
			binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
		}
	}
}

signed main() {
	fastio;
	cin >> R;

	vector<int> sieve(R + 1, 0);
	for (int i = 2; i <= R; i++) {
		if (sieve[i]) continue;
		sieve[i] = 1;
		for (int j = 2 * i; j <= R; j += i) {
			if (sieve[j] == -1) continue;
			if (j % (i * i) == 0) { sieve[j] = -1; continue; }
			sieve[j]++;
		}
	}

	int res = R * R;
	for (int i = 2; i <= R; i++) {
		int x = R / i;
		x *= x;
		if (sieve[i] == -1) continue;
		else if (sieve[i] % 2) {
			// odd, subtract
			res -= x;
		}
		else {
			// even subtract
			res += x;
		}
	}
	dbgstd(sieve);

	int nres = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= R; j++) {
			if (gcd(i, j) == 1) nres++;
		}
	}
	debug(res);
	debug(nres);

	return 0;
}