/**
*    author:  lazyhash(yashkundu)
*    created: 02 Sep, 2024 | 22:29:00
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

vector<int> g[MAXN];

int n, k;
int x, y;
int u, v;

bool good[MAXN];

int depx[MAXN], depy[MAXN];

int cnt = 0;


bool dfs(int v, int p) {
    bool b = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        if(dfs(u, v)) {
            cnt++;
            b = 1;
        }
    }
    return b || good[v];
}


void dfs2(int v, int p, int* dep) {
    for(int u: g[v]) {
        if(u==p) continue;
        dep[u] = dep[v] + 1;
        dfs2(u, v, dep);
    }
}


 
void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) g[i].clear();
    fill(good, good+n, 0);

    cin >> x >> y, x--, y--;

    for(int i=0;i<k;i++) {
        cin >> u, u--;
        good[u] = 1;
    }

    for(int i=0;i<n-1;i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    cnt = 0;
    dfs(x, -1);
    depx[x] = 0;
    depy[y] = 0;

    dfs2(x, -1, depx);
    dfs2(y, -1, depy);

    int ans = (int)1e9+10;

    for(int i=0;i<n;i++) if(good[i]) {
        ans = min(ans, 2*cnt - depx[i] + depy[i]);
    }

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