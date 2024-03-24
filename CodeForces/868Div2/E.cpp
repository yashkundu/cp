/**
*   author: lazyhash(yashkundu)
*   created: 03 May, 2023 | 08:42:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+100;
vector<int> g[N];
vector<bool> vis(N, 0);
vector<bool> dp(N, 0), pre(N, 0);


int dfs(int v) {
    int cnt = 1;
    vis[v] = 1;
    for(int u: g[v]) {
        if(vis[u]) continue;
        cnt += dfs(u);
    }
    return cnt;
}

 
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    for(int i=0;i<n;i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> v;

    for(int i=0;i<n;i++) {
        if(!vis[i]) v.push_back(dfs(i));
    }

    for(int i=0;i<=n;i++) {
        int x = max(0, i-r), y = max(0, i-l+1);
        if(pre[y]-pre[x]==y-x) dp[i] = 0;
        else dp[i] = 1;
        pre[i+1] = pre[i] + dp[i];
    }

    int pWin = 0;
    for(int &x: v) pWin += dp[x];

    if(pWin&1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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