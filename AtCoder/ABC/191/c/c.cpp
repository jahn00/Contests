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

int R, C;
const int mxn = 11;
const char black = '#', white = '.';
char m[mxn][mxn];

int count_segments(int row) {
    int segments = 0;
    char prev = '\0';
    for (int c = 1; c + 1< C; c++) {
        char mrc = m[row][c];
        if (mrc == prev) {
            while (c < C and m[row][c] == prev) c++;
            c--; continue;
        }
        if (mrc == white) {
            segments++; prev = white;
        } else {
            prev = black;
        }
    }
    return segments;
}

int count_v_segments(int col) {
    int segments = 0;
    char prev = '\0';
    for (int r = 1; r + 1< R; r++) {
        char mrc = m[r][col];
        if (mrc == prev) {
            while (r < R and m[r][col] == prev) r++;
            r--; continue;
        }
        if (mrc == white) {
            segments++; prev = white;
        } else {
            prev = black;
        }
    }
    return segments;

}

struct Edge {
  int from, to, w;
  Edge(int u, int v, int w){
    from = u;
    to = v;
    this->w = w;
  }
};

vector<Edge> graph[100010];

vector<int> dijkstra(vector<Edge> g[], int source) {
    // dist[u] == distance of vertex u from source vertex
  vector<int> dist(N, 0x3f3f3f3f); 
  dist[source] = 0;
    // min heap of (dist, vertex)
  priority_queue<pair<int, int>, vector<pair<int,int>>,
    greater<pair<int,int>> > pq; 

  pq.push({0, source});
  while(!pq.empty()) {
    auto top = pq.top(); pq.pop();

    for (auto e : g[top.second]) {
      int to = e.to;
      if (dist[top.second] + e.w < dist[to]) {
        dist[to] = dist[top.second] + e.w;
        pq.push({dist[to], to});
      }
    }
  }
  return dist;
}

signed main() {
    fastio;
    cin >> R >> C;
    rep(r, R) {
        rep(c, C) {
            cin >> m[r][c];
        }
    }

    int horiztonal_segments = 0;
    rep(r, R) {
        // count contiguous segments
        horiztonal_segments += count_segments(r);
    }
    //swap(R,C);
    /*
    rep(r, R) {
        rep(c, C) {
            cout << m[r][c];
        }
        cout << endl;
    }
    */

    int vertical_segments = 0;
    rep(c, C) {
        vertical_segments += count_v_segments(c);
    }

    /*
    cout << "h: " << horiztonal_segments << endl; 
    cout << "v: " << vertical_segments << endl;
    */
    cout << horiztonal_segments + vertical_segments << endl; 
    return 0;
}