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
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

int sweight, aweight;
int solve(int cap, int& nsw, int& nax) {


}

signed main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int p, f, nsw, nax, maxi = 0;
        cin >> p >> f >> nsw >> nax >> sweight >> aweight;
        int numswords = nsw;
        int numaxes = nax;
        int res1 = solve(p, numswords, numaxes);
        int res2 = solve(f, numswords, numaxes);
        maxi = res1 + res2;


        int numswords = nsw;
        int numaxes = nax;
        res1 = solve(f, numswords, numaxes);
        res2 = solve(p, numswords, numaxes);
        maxi = max(maxi, res1 + res2);
        cout << maxi << endl;
    }
}