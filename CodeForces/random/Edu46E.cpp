/**
*   author: lazyhash(yashkundu)
*   created: 06 Apr, 2024 | 16:57:29
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
 
const int N = 3e5+10;
vector<int> g[N];
vector<int> bG[N];
int par[N];
int rnk[N];
int tin[N]={0}, low[N]={0};
int timer = 0;
int vis[N] = {0};
vector<pair<int, int>> bridges;
int dis[N];
int root = 0;


int n, m;


int find(int v) {
    if(par[v]==v) return v;
    return par[v] = find(par[v]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return;
    if(rnk[a]>rnk[b]) swap(a, b);
    par[a] = b;
    if(rnk[a]==rnk[b]) rnk[b]++;
}

void dfs(int v, int p=-1) {
    vis[v] = 1;
    low[v] = tin[v] = timer++;
    for(int u: g[v]) {
        if(u==p) continue;
        if(vis[u]) {
            // back edge
            low[v] = min(low[v], tin[u]);
        } else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u]>tin[v]) {
                bridges.emplace_back(u, v);
            } else {
                merge(u, v);
            }
        }
    }
}

void buildBridgeTree() {
    for(auto [a, b]: bridges) {
        a = find(a);
        b = find(b);
        root = a;
        bG[a].push_back(b);
        bG[b].push_back(a);
    }
}


// (v, dis[v])
pair<int, int> bfs(int x) {
    for(int i=0;i<n;i++) dis[i] = n;

    queue<int> q;
    dis[x] = 0;
    q.push(x);

    int lastV = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        lastV = v;
        for(int u: bG[v]) {
            if(dis[v]+1<dis[u]) {
                dis[u] = 1 + dis[v];
                q.push(u);
            }
        }
    }

    return {lastV, dis[lastV]};

}





void solve() {
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        par[i] = i;
        rnk[i] = 0;
    }

    
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    buildBridgeTree();
    auto p = bfs(root);
    auto p2 = bfs(p.first);


    cout << p2.second << "\n";
    
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