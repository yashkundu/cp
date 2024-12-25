/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jul, 2024 | 12:32:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;
const int inf = int(1e9)+10;


int c[MAXN];
bool clr[MAXN];
vector<int> g[MAXN];

int res[MAXN];
int dis[MAXN];


int n;
int u, v;
int ans;


void dfs(int v, int p = -1) {
    if(dis[v]>=ans) return;
    for(int u: g[v]) {
        if(u==p) continue;
        if(dis[v]+1<dis[u]) {
            dis[u] = 1+dis[v];
            dfs(u, v);
        } else ans = min(ans, dis[v]+1+dis[u]);
    } 
}


 
void solve() {
    cin >> n >> c[0];
    c[0]--;

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=1;i<n;i++) cin >> c[i], c[i]--;


    for(int i=0;i<n-1;i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    ans = inf;
    fill(dis, dis+n, inf);
    fill(clr, clr+n, 0);

    dis[c[0]] = 0;
    dfs(c[0]);
    clr[c[0]] = 1;

    for(int i=1;i<n;i++) {
        dis[c[i]] = 0;
        dfs(c[i]);
        clr[c[i]] = 1;
        res[i] = ans;
    }

    for(int i=1;i<n;i++) cout << res[i] << " ";
    cout << "\n";





    
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