#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; i < (n); i++)
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

const int maxn = 101;
int A[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  double M;
  cin >> N >> M;
  double sum = 0;
  for(int i = 0;i<N;i++){
    cin >> A[i];
    sum += A[i];
  }
  int cnt = 0;
  for(int i = 0;i<N;i++){
    if (A[i] >= sum / 4 / M) {
      cnt ++;
    }
  }
  if (cnt >= M) Out("Yes");
  else Out("No");
  return 0;
}
