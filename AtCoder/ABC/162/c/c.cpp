#include <iostream>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }
int gcd(int a, int b) {
  return (a % b) ? gcd(b, a%b) : b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  unsigned long long res = 0;
  for (int a = 1; a <= k; a++) {
    for (int b = 1; b <= k; b++) {
      for (int c = 1; c <= k; c++) {
        res += gcd(a, gcd(b,c));
      }
    }
  }
  cout << res << endl;

}
