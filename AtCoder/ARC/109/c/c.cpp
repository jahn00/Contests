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

// failure function builder
vector<int> buildkmp(const string& t) { 
  int m = t.size();
  vector<int> f(m);
  f[0] = 0;
  int i = 1, len = 0;
  for (; i < m; ++i) {
    while (len > 0 && t[len] != t[i]) len = f[len - 1];
    if (t[len] == t[i]) len++;
    f[i] = len;
  }
  return f;
}

void kmp(string& s, string& find) {
    vector<int> f = buildkmp(find);
    int n = s.size();
    int k = 0;
    for (int i = 1; i <= n; i++) {
        while (k >= 0 && s[k + 1] != find[i])
            k = f[k];
        k++;
        if (k == m) {
            k = f[k];
        }
    }
}

signed main() {
    fastio;
}