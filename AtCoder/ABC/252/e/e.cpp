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
#define print(x) cout << (#x) << " is " << (x) << endl;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define sz(v) ((int)(v).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define inf 0x3f3f3f3f
#define nl '\n'
using namespace std;

struct Edge {
    int u, v, w, id;
    Edge(int u, int v, int w, int id): u(u), v(v), w(w), id(id) {};

    bool operator<(const Edge& rhs) const {
        return this->w > rhs.w;
    };
};

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(u, v, w, i);
        g[v].emplace_back(v, u, w, i);
    }

    vector<std::array<int, 3>> dist(n); // (distance, from vertex, road id)
    rep (i, n) {
        dist[i][0] = 1e9;
        dist[i][1] = -1;
        dist[i][2] = -1;
    }
    priority_queue<pair<int, int>> pq;
    dist[0][0] = 0;
    pq.emplace(0, 0);

    while (pq.size()) {
        auto top = pq.top(); pq.pop();
        int weight = -top.first;
        int u = top.second;

        for (auto& edge : g[u]) {
            int v = edge.v, w = edge.w, id = edge.id;

            if (weight + w < dist[v][0]) {
                dist[v][0] = weight + w;
                dist[v][1] = u;
                dist[v][2] = id;

                pq.emplace(-dist[v][0], v);
            }
        }
    }

    int i = n - 1;
    for (int i = 1; i < n; i++) {
        cout << dist[i][2] + 1 << " ";
    }



}