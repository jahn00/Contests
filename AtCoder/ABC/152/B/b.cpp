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
  int a, b;
  cin >> a >> b;
  char aa = '0' + a;
  char bb = '0' + b;
  string resa;
  string resb;
  for (int i = 0; i < b; i++) resa += aa;
  for (int i = 0; i < a; i++) resb += bb;

  if (resa < resb) {
    Out(resa); return 0;
  } else {
    Out(resb); return 0;
  }

}
