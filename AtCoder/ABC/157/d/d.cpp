/* 
    Author : Jeff Ahn
    Mon 22 Jun 2020 05:21:35 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'


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

const int mxn = 1e5+10;
int a[mxn], b[mxn], c[mxn], d[mxn];

signed main() {
  fastio;
  int n, m, k;
  cin >> n >> m >> k;
  UnionFind dsu(n);

  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    dsu.uni(a[i], b[i]);
  }
  rep(i, k) {
    cin >> c[i] >> d[i];
    c[i]--; d[i]--;
  }

  vector<int> res(n);
  rep(i, n) {
    res[i] = dsu.size(i) - 1;
  }

  rep(i, m) {
    int aa = a[i], bb = b[i];
    res[aa]--;
    res[bb]--;
  }
  rep(i, k) {
    int cc = c[i], dd = d[i];
    if (dsu.find(cc) != dsu.find(dd)) continue;
    res[cc]--;
    res[dd]--;
  }
  for (auto r : res) cout << r << " ";
}
