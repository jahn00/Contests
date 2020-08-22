#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int k = ri(), q = ri();
	int d[k];
	for (auto &i : d) i = ri();

	for (int i = 0; i < q; i++) {
		int n = ri();
		int first = ri();
		int mod = ri();
		first %= mod;
		int b[k];
		int inc[k];
		for (int j = 0; j < k; j++) {
			b[j] = d[j] % mod;
			inc[j] = !!b[j]; // 0s stay 0, non-zeros become 1
		}
		int big = (n - 1) / k;
		int res = 0;
		ll sum = first;
		sum += std::accumulate(b, b + k, 0LL) * big;
		res += std::accumulate(inc, inc + k, 0LL) * big;
		sum += std::accumulate(b, b + (n - 1) % k, 0LL);
		res += std::accumulate(inc, inc + (n - 1) % k, 0LL);
		printf("%lld \n", res - sum / mod);
	}
	return 0;
}

