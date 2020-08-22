#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }
const int maxn = 2e5;
int p[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  int res = 0;
  int mini = maxn + 1;
  for (int i = 0; i < n; i++) {
    mini = min(mini, p[i]);
    if (mini >= p[i]) res++;
  }
    Out(res); return 0;
}
