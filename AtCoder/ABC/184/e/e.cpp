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
const int mn = 2010;

int m[mn][mn];
int dir[5] = {-1,0,1,0,-1};


signed main() {
    fastio;
    cin >> R >> C;

    vector<vector<pair<int,int>>> neigh(26);
    pair<int,int> start, end;
    rep(r,R) {
        rep(c,C) {
            char x;
            cin >> x;
            if (x == 'S') {
                start.first = r;
                start.second = c;
                m[r][c] = -1;
            }
            else if (x == 'G') {
                end.first = r;
                end.second = c;
                m[r][c] = -1;
            }
            else if (x == '.') {
                // free passage
                m[r][c] = -1;
            }
            else if (x == '#') {
                // blocked / wall
                m[r][c] = -2;
            }
            else {
                // character
                m[r][c] = x - 'a';
                neigh[x-'a'].emplace_back(r, c);
            }
        }
    }

    deque<pair<int,int>> q;
    q.push_back(start);
    vector<vector<int>> v(R, vector<int>(C, 0));
    v[start.first][start.second] = 1;

    vector<vector<int>> dist(R, vector<int>(C, inf));
    dist[start.first][start.second] = 0;

    while (!q.empty()) {

            auto top = q.front(); q.pop_front();
            int r = top.first, c = top.second;
            if (r==end.first and c==end.second) {
                cout << dist[r][c] << endl;
                return 0;
            }

            int mrc = m[r][c];
            // if current cell is a-z, then we do multisource 0-cost jump to neighbors of same letter
            if (0 <= mrc and mrc < 26) {
                for (pair<int,int>& p : neigh[mrc]) {
                    if (dist[p.first][p.second] > dist[r][c] + 1) {
                        q.emplace_back(p);
                        dist[p.first][p.second] = dist[r][c] + 1;
                        v[p.first][p.second] = 1;
                    }
                }
                neigh[mrc].clear();
            }
            // check cardinal neighbors of current cell
            for (int d = 0; d < 4; d++) {
                int dr = r + dir[d];
                int dc = c + dir[d+1];
                if (dr<0 or dr>=R or dc<0 or dc>=C or v[dr][dc] or m[dr][dc] == -2) continue;
                assert(m[dr][dc] == -1 or (0 <= m[dr][dc] and m[dr][dc] < 26));
                q.emplace_back(dr,dc);
                v[dr][dc] = 1;
                dist[dr][dc] = dist[r][c] + 1;
            }
    }
    cout << -1 << endl;
    return 0;
}