/**
*    author:  lazyhash(yashkundu)
*    created: 08 Oct, 2024 | 21:12:21
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;
const int LG = 30;

vector<pair<int, int>> g[MAXN];
bool vis[MAXN];

int n, m;
int u, v, w;


int dfs(int v, int num) {
    vis[v] = 1;
    int cnt = 1;
    for(auto [u, w]: g[v]) {
        if(vis[u]) continue;
        if(w&num) continue;
        cnt += dfs(u, num);
    }
    return cnt;
}
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<m;i++) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }


    int cur = 0;

    for(int j=LG-1;j>=0;j--) {
        fill(vis, vis+n, 0);
        cur ^= 1<<j;
        if(dfs(0, cur)!=n) cur ^= 1<<j;
    }

    int ans = ((1<<LG)-1)^cur;

    cout << ans << "\n";


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/