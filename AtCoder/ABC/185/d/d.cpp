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

int N, M;
vector<int> blue;
vector<pair<int,int>> seg;

signed main() {
    fastio;
    cin >> N >> M;
    if (M == 0) {
        // no blues, color all red once
        cout << 1 << endl;
        return 0;
    }
    if (M == N) {
        // if all blue squares, no coloring required
        cout << 0 << endl;
        return 0;
    }
    rep(i, M) {
        int ai; cin >> ai;
        blue.push_back(ai);
    }
    // make intervals for [start, end] blue contig. segments
    sort(all(blue));
    for (int i = 0; i < M;) {
        int bi = blue[i]; // bi = index of the ith blue piece from the left
        int start = bi;
        int j = i;
        while (j + 1 < M and blue[j+1] == bi + 1) {
            j++; bi++;
        }
        seg.push_back({start, blue[j]});
        i = j + 1;
    }
    if (seg.back().second != N) {
        seg.push_back({N+1, N+1});
    }
    int end;
    int mini = inf;
    int i = 0;
    vector<int> seg_w;
    if (seg[0].first == 1) {
        end = seg[0].second + 1;
        i = 1;
    } else {
        end = 1;
    }
    for (; i < seg.size(); i++) {
        int nstart = seg[i].first;
        int diff = nstart - end;
        seg_w.emplace_back(diff);
        mini = min(mini, diff);
        end = seg[i].second + 1;
    }
    // use mini to find the actual count
    int res = 0;
    for (auto& x : seg_w) {
        res += (x + mini - 1) / mini;
    }
    cout << res << endl;
    return 0;
}