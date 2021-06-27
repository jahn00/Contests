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

bool check(string s) {
    do {
        int num = stoi(s);
        cerr << num << endl;
        if (num % 8 == 0) {
            return true;
        }
    } while(next_permutation(all(s)));
    return false;
}

signed main() {
    fastio;
    string s;
    cin >> s;
    unordered_map<char,int> mp;
    for (auto& c : s) {
        mp[c]++;
    }
    if (s.size() == 1) {
        if(s[0] =='8') {
            cout << "Yes" << endl;
            return 0;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    else if (s.size() == 2) {
        int num = stoi(s);
        reverse(all(s));
        int num2 = stoi(s);
        if (!(num%8 and num2%8)) {
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        vector<pair<char, int>> a(all(mp));
        int n = a.size();
        s = "";
        for (int i = 0; i < n; i++) {
            s += a[i].first;
            a[i].second--;
            for (int j = 0; j < n; j++) {
                if (a[j].second == 0) continue;
                a[j].second--;
                s += a[j].first;
                for (int k = 0; k < n; k++) {
                    if (a[k].second == 0) continue;
                    a[k].second--;
                    s += a[k].first;
                    // cout << s << endl;
                    if (check(s)) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                    s.pop_back();
                    a[k].second++;
                }
                s.pop_back();
                a[j].second++;
            }
            s.pop_back();
            a[i].second++;
        }
    }
    cout << "No" << endl;
    return 0;
}