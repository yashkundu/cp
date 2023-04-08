/**
*   author: lazyhash(yashkundu)
*   created: 21 Mar, 2023 | 23:03:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+10;
const int SQRT = 320;

vector<vector<ll>> cache(N, vector<ll>(SQRT, -1));
vector<int> a(N, 0);
vector<int> g[N];
vector<int> cnt(N, 0), rnk(N, 0), p(N, -1);


void dfs(int v, int d) {
    rnk[v] = cnt[d]++;
    for(int u: g[v]) {
        dfs(u, d+1);
    }
}

ll calc(int x, int y) {
    if(x==-1) return 0LL;
    if(rnk[y]<SQRT && cache[x][rnk[y]]!=-1) return cache[x][rnk[y]];
    ll ans = 1LL*a[x]*a[y] + calc(p[x], p[y]);
    if(rnk[y]<SQRT) cache[x][rnk[y]] = ans;
    return ans;
}

 
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=1;i<n;i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }

    dfs(0, 0);

    while(q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << calc(x, y) << "\n";
    }


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/* stuff you should look for
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/