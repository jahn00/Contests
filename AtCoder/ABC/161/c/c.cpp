#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ull = unsigned long long;
template<typename T> void Out(T x) { cout << x << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull N, K;
  cin >> N >> K;

  long long mini = N % K;
  cout << min(mini, (long long)abs(mini - (long long)K)) << endl;

}
