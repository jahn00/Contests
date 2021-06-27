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
#define inf 0x3f3f3f3f3f3f3f3f
#define nl '\n'
using namespace std;

int solve(vector<int>& a) {
	int n = a.size();
	vector<int> d(n + 1);

	for (int i = 0; i < n; i++) d[i] = 1;

	for (int i = 0; i < n; i++) {
		int ai = a[i];
		for (int j = 0; j < i; j++) {
			int aj = a[j];
			if (ai % aj == 0 and (d[j] + 1 > d[i])) {
				d[i] = d[j] + 1;
			}
		}
	}
	return *max_element(all(d));
}

signed main() {
	fastio;
}