//#define TIMER_
#include <bits/stdc++.h>
using namespace std;
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using ull = unsigned long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main() {
  fastio;
	int N, M, S;
	cin >> N >> M >> S;

	struct edge{
	  int to, cost;
		ll time;
	};

	vvec<edge> g(N);

	for(int i=0;i<M;i++){
		int u,v, a, b;
		cin >> u >> v >> a >> b;
		u--; v--;
		g[u].push_back({v, a, b});
		g[v].push_back({u, a, b});
	}

	vec<int> C(N), D(N);
	for(int i = 0; i < N; i++) cin >> C[i] >> D[i];
	int maxi = 5001;

	struct state {
		int node, s;
		ll dist;
		bool operator<(const state& R)const{
        return dist > R.dist;
    }
	};

  priority_queue<state> Q;
  ll inf = 1e18;
  vvec<ll> dp(N + 1, vec<ll>(maxi + 1, inf));
  S = min(S, maxi);
  dp[0][S] = 0; // dp[v][S] -> shortest time to reach v with S silver coins
  Q.push({0, S, 0});

	while(!Q.empty()){
	    auto top = Q.top(); 
      Q.pop();
      auto cur = top.node;
      auto s = top.s;
      auto d = top.dist;

      // cerr << cur << " " << s << " " << d << "\n";
			if (dp[cur][s] < d) continue;
			int ns = min(maxi, s + C[cur]);
			ll nd = d + D[cur];
			if (dp[cur][ns] > nd) {
					dp[cur][ns] = nd;
					Q.push({cur, ns, nd});
			}

			for (auto& e : g[cur]){
					if (s < e.cost) continue;
					int ne = e.to;
					int ns = s - e.cost;
					ll nd = d + e.time;
					if (dp[ne][ns] > nd){
							dp[ne][ns] = nd;
							Q.push({ne, ns, nd});
					}
			}
	}

	for(int i = 1; i < N; i++) 
    cout << *min_element(dp[i].begin(), dp[i].end()) << "\n";
  
  #ifdef TIMER_
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  #endif
}
