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
#define endl '\n'
using namespace std;

struct UnionFind {

  vector<int> id;
  vector<int> Size;

  UnionFind(int n) {
    id.resize(n); Size.resize(n, 1);
    for (int i = 0; i < n; i++) id[i] = i;
  }

  int find(int u) {
    return (id[u] == u) ? u : id[u] = find(id[u]);
  }

  bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    id[v] = u;
    Size[u] += Size[v];
    return true;
  }

  int size(int u) {
    u = find(u);
    return Size[u];
  }
};

int n, m;

signed main() {
    fastio;
    cin >> n >> m;
    UnionFind dsu(n);
    int res = 1;
    rep (i, m) {
        int ai, bi;
        cin >> ai >> bi;
        ai--, bi--;
        dsu.uni(ai, bi);
        res = max(res, dsu.size(ai));
    }
    cout << res << endl;
}