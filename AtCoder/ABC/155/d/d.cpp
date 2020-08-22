#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll N, k, posp, negp, zedp, cn, c0, cp;
const int maxn = 2e5 + 1;
ll a[maxn];

ll solveneg() {
  vector<ll> pos(a + N - cp, a + N);
  vector<ll> neg(a, a + cn);
  ll r = pos[0] * neg.back();
  ll l = pos.back() * neg[0];
  reverse(pos.begin(), pos.end()); // desc 3, 2, 1
  reverse(neg.begin(), neg.end()); // desc -1, -2, -3
  while(l <= r) {
    ll mi = l + (r - l) / 2;
    ll cnt = 0;
    // two pointer
    for (int i = 0, j = 0; i < neg.size(); i++) {
      for (; j < cp && neg[i] * pos[j] <= mi; j++);
      cnt += j;
    }
    if (cnt < k)
      l = mi + 1;
    else 
      r = mi - 1;
  }
  return l;
}

ll solvepos() {
  vector<ll> pos(a + N - cp, a + N);
  vector<ll > neg(a, a + cn);
  reverse(neg.begin(), neg.end());
  ll l = LLONG_MAX, r = LLONG_MIN;
  // -1 -2 -3 -4 -5
  if (pos.size() > 0) {
    l = pos[0] * pos[0];
    r = pos.back() * pos.back();
  }
  if (neg.size() > 0) {
    l = min(l, neg[0] * neg[0]);
    r = max(r, neg.back() * neg.back());
  }
  while(l <= r) {
    ll mi = l + (r - l) / 2;
    ll cnt = 0;
    for (int i = cp - 1, j = 0; i >= 0; i--) {
      for (; j < i && pos[i] * pos[j] <= mi; j++);
      cnt += min(j, i);
    }
    for (int i = cn - 1, j = 0; i >= 0; i--) {
      for (; j < i && neg[i] * neg[j] <= mi; j++);
      cnt += min(j, i);
    }
    if (cnt < k)
      l = mi + 1;
    else 
      r = mi - 1;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> k;
  cp = 0, cn = 0, c0 = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      cp++;
    } else if (a[i] < 0) {
      cn++;
    } else c0++;
  }

  posp = cp * (cp - 1) / 2 + cn * (cn - 1) / 2;
  zedp = c0 * (cn + cp) + c0 * (c0 - 1) / 2;
  negp = cn * cp;

  ll ans;
  sort(a, a + N);
  if (k > zedp + negp) {
    k -= (zedp + negp);
    ans = solvepos();
  }
  else if (k <= negp) {
    ans = solveneg();
  } else {
    ans = 0;
  }
  cout << ans << endl;
}
