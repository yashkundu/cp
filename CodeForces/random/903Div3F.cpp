/**
*    author:  lazyhash(yashkundu)
*    created: 05 Jul, 2024 | 14:14:35
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

vector<int> g[MAXN];
int dis[MAXN];
bool marked[MAXN];

int n, k;
int u, v, a;
int first, dia;

void dfs(int v, int p = -1) {
    for(int u: g[v]) {
        if(u==p) continue;
        dis[u] = 1 + dis[v];
        dfs(u, v);
    }
}

 
void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        g[i].clear();
        marked[i] = 0;
    }

    for(int i=0;i<k;i++) {
        cin >> a;
        a--;
        marked[a] = 1;
        first = a;
    }

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dis[first] = 0;
    dfs(first);

    first = -1;
    for(int i=0;i<n;i++) {
        if(!marked[i]) continue;
        if(first==-1 || dis[i]>dis[first]) first = i;
    }

    dis[first] = 0;
    dfs(first);

    dia = 0;
    for(int i=0;i<n;i++) {
        if(!marked[i]) continue;
        dia = max(dia, dis[i]);
    }


    cout << (dia+1)/2 << "\n";




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