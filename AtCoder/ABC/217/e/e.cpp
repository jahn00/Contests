/* 
    Author : Jeff Ahn
    Sat 04 Sep 2021 05:32:31 AM PDT 
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'

int Q;

signed main() {
  fastio;
  cin >> Q;
  queue<int> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  int k = 0, counter = 0;

  rep(_, Q) {
    int qi; cin >> qi;
    if (qi == 1) {
      // append
      int xi; cin >> xi;
      q.push(xi);
      k++;
    }
    else if (qi == 2) {
      // print
      if (counter == 0) {
        // if we printed from all previous sorted elements, print from the
        // normie q instead
        cout << q.front() << endl; q.pop();
      }
      else {
        cout << pq.top() << endl; pq.pop();
        counter--;
      }
    }
    else if (qi == 3) {
      // sort
      while(q.size()) {
        pq.emplace(q.front()); q.pop();
      }
      counter = pq.size() + q.size();
    }
  }

}
