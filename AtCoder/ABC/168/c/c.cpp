//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);

struct point {
  long double x,y;

  point(long double r, long double theta) {
    this->x = r*cos(pi/2 - theta);
    this->y = r*sin(pi/2 - theta);
  }

};

double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  fastio;
  long double a, b, h, m;
  cin >> a >> b >> h >> m;

  point hour = point(a, (h*(pi/6) + pi/6*m/60));
  point min = point(b, m * pi/30);
  cout << setprecision(20);
  cout << dist(min, hour) << endl;




  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
