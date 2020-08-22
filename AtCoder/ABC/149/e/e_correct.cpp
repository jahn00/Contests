#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (1e9)
ll N, M;
vector<ll> A;
ll sum[105000];

ll f(ll x) {
    ll ret = 0;
    int j = N - 1;
    for(int i = 0; i < N; i++) {
        while( j >= 0 && A[i] + A[j] >= x) j--;
        ret += N - j - 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    A.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // sort
    sort(A.begin(), A.end());
    // compute prefix sums
    for(int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + A[i];
    }
    ll ok = 0;
    ll ng = 2e5 + 1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (f(mid) >= M) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ll ans = 0;
    int j = N - 1;
    // two pointer
    for(int i = 0; i < N; i++) {
        while (j >= 0 && ok <= A[i] + A[j]) j--;
        ans += (N-j-1) * A[i] + (sum[N] - sum[j+1]);
    }
    cerr << f(ok) << endl;
    ans -= (f(ok) - M) * ok;
    cout << ans << endl;
    return 0;
}

