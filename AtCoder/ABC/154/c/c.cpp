#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
	unordered_map<int, int>a;
	for (int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		if(a[ai]) { cout << "NO" << endl; return 0;}
		a[ai]++;
	}
	cout << "YES" << endl;
	return 0;
}
