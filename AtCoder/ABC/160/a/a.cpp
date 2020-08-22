#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  if (s[2] == s[3] && s[4] == s[5]){
    Out("Yes");
    return 0;
  }
  Out("No");
  
}
