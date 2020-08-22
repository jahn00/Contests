#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using ull = unsigned long long;

int main() {
  fastio;
  int N, M;
  cin >> N >> M;
  int sum = 0;
  int a;
  rep(i, 0, M) {
    cin >> a;
    sum += a;
    if (sum > N) { cout << "-1\n"; return 0; }
  }
  cout << N - sum << endl;
  return 0;
}
