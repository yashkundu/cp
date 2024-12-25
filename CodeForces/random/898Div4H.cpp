/**
*    author:  lazyhash(yashkundu)
*    created: 05 Jul, 2024 | 16:08:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MAXN = int(2e5) + 10;

vector<int> g[MAXN];
bool inCycle[MAXN];
bool vis[MAXN];
int dis[MAXN];

int n, a, b, u, v;
int first = -1;


bool dfs1(int v, int p = -1) {
    if(vis[v]) {
        inCycle[v] = 1;
        first = v;
        return true;
    }
    vis[v] = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        if(dfs1(u, v)) {
            if(first==v) first = -1;
            if(first!=-1) inCycle[v] = 1;
            return true;
        }
    }
    return false;
}


void calcDis(int v) {
    queue<int> q;
    fill(dis, dis+n, -1);
    dis[v] = 0;
    q.push(v);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int u: g[v]) {
            if(dis[u]==-1) {
                dis[u] = 1 + dis[v];
                q.push(u);
            }
        }
    }
}


int ev = -1;
int disv = -1, dism = -1;


void solve() {
    cin >> n >> a >> b;
    a--, b--;

    for(int i=0;i<n;i++) g[i].clear();
    fill(vis, vis+n, 0);
    fill(inCycle, inCycle+n, 0);

    for(int i=0;i<n;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    first = -1;
    dfs1(0);

    calcDis(b);

    ev = -1;
    for(int i=0;i<n;i++) {
        if(!inCycle[i]) continue;
        if(ev==-1 || dis[i]<dis[ev]) ev = i;
    }

    disv = dis[ev];

    calcDis(a);
    dism = dis[ev];

    cout << ((disv<dism)?"YES":"NO") << "\n";






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