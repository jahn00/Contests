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
#include <bitset>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

const int mn = 2e5 + 10;
int g[mn][mn];
int f[mn][mn];
int R, C;
signed main() {
    fastio;
        cin >> R >> C;
        int srow,scol,erow,ecol;
        cin >> srow >> scol;
        cin >> erow >> ecol;
        --srow,--scol,--erow,--ecol;
        bool ok = false;
        deque<pair<int,int> > dq;
        memset(f, 0x3f, sizeof f);
        f[srow][scol] = 0;
        dq.push_back({srow,scol});
        while(!dq.empty()){
            pair<int,int> cur_node = dq.front();
            dq.pop_front();
            int row = cur_node.first;
            int col = cur_node.second;
            if(row == erow && col == ecol){
                ok = true;
                break;
            }
            for(int dx = -2;dx <= 2;++dx){
                for(int dy = -2;dy <= 2;++dy){
                    int nrow = row + dx;
                    int ncol = col + dy;
                    if(nrow == row && ncol == col)
                        continue;
                    if(nrow < 0 || ncol < 0 || nrow >= h || ncol >= w)
                        continue;
                    int w = 1;
                    if(grid[nrow][ncol] == '#')
                        continue;
                    if((abs(nrow-row) == 1 && abs(ncol-col) == 0) || (abs(ncol-col) == 1 && abs(nrow-row) == 0))
                        w = 0;
                    if(dist[nrow][ncol] > dist[row][col] + w){
                        dist[nrow][ncol] = dist[row][col] + w;
                        if(w == 0)
                            dq.push_front({nrow,ncol});
                        else
                            dq.push_back({nrow,ncol});
                    }
                }
            }
        }
        if(!ok)
            dist[erow][ecol] = -1;
        cout << dist[erow][ecol] << "\n";
}