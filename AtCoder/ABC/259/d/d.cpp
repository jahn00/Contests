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
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;

using ll = long long;

struct P {
  ll x;
  ll y;
  P (ll x, ll y): x(x), y(y) {}
};

ll distance(const P& lhs, const P& rhs) {
    ll dx = (lhs.x - rhs.x);
    ll dy = (lhs.y - rhs.y);
    ll res =  dx*dx + dy*dy;
    return res;
}

struct C {
  P p;
  ll r;
  int id;
  C(ll x, ll y, ll r, int i): p(x,y), r(r), id(i) {}

  bool intersect(const C& rhs) {
    ll dist = distance(this->p, rhs.p);

    ll sum2 = (this->r + rhs.r) * (this->r + rhs.r);
    if (dist > sum2) {
      //cerr << "circles are disjoint" << endl;
      return false;
    }

    if (dist < (rhs.r - this->r) * (rhs.r - this->r)) {
      //cerr << "circles are enclosed" << endl;
      return false;
    }
    return true;
  }
};


signed main() {
    fastio;
    ll N, SX, SY, TX, TY;
    cin >> N >>SX >> SY >> TX >> TY;
    P source(SX, SY);
    P sink(TX, TY);
    int source_id = -1, sink_id = -1;

    vector<C> A;
    for (int i = 0; i < N; i++) {
      ll x, y, r;
      cin >> x >> y >> r;
      A.emplace_back(x, y, r, i);
      if (distance(A[i].p, source) == r*r) {
        source_id = i;
        cerr << "source id: " << i << endl;
      }
      if (distance(A[i].p, sink) == r*r) {
        sink_id = i;
        cerr << "sink id: " << i << endl;
      }
    }
    if (source_id == -1 and sink_id == -1) {
      cerr << "source and sink not found" << endl;
      cout << "No" << endl;
      return 0;
    }

    vector<vector<int>> g(N);
    for (int i = 0; i < N; i++) {
      C u = A[i];
      for (int j = i + 1; j < N; j++) {
        C v = A[j];
        if (u.intersect(v)) {
          //cerr << i << " overlaps with " << j << endl;
          g[u.id].push_back(v.id);
          g[v.id].push_back(u.id);
        }
      }
    }

    vector<bool> visited(N, false);
    function<void(int)> dfs = [&](int u) {
      if (visited[u]) return;
      visited[u] = true;
      for (auto v : g[u]) {
        dfs(v);
      }
    };

    dfs(source_id);
    if (visited[sink_id]) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }

    return 0;
}
