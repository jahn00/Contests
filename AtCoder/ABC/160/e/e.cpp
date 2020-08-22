#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }
const int maxn = 1e5 + 1;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> red(A), gr(B), none(C);
  for (int i = 0; i < A; i++) cin >> red[i];
  for (int i = 0; i < B; i++) cin >> gr[i];
  for (int i = 0; i < C; i++) cin >> none[i];
  vector<int> P;
  sort(red.begin(), red.end(), greater<int>());
  for (int i = 0; i < X; i++) P.pb(red[i]);
  sort(gr.begin(), gr.end(), greater<int>());
  for (int i = 0; i < Y; i++) P.pb(gr[i]);
  sort(none.begin(), none.end(), greater<int>());
  for (int i = 0; i < min(X+Y, C); i++) P.pb(none[i]);
  sort(P.begin(), P.end(), greater<int>());
  ll res = 0;
  for (int i = 0; i < X+Y; i++) res += P[i];
  cout << res << endl;
  return 0;

}
