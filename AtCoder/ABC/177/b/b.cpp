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

string s, sub;

signed main() {
    fastio;
    cin >> s >> sub;
    // change s so sub is a substr of s
    int res = sub.size();

    for (int i = 0; i + sub.size() - 1 < s.size(); i++) {
        int cnt = sub.size();
        for (int j = 0; j < sub.size(); j++) {
            if (s[i + j] == sub[j]) {
                cnt--;
            }
        }
        res = min (res, cnt);
    }
    cout << res << endl;
}