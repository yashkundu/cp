/**
*   author: lazyhash(yashkundu)
*   created: 14 Jan, 2024 | 23:26:41
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int M = 30;
const int K = 20;
int a[N];
vector<int> g[N];
int par[N][M][K] = {0};
int par2[N][K] = {0};
int tin[N], tout[N];
int timer = 0;
int dep[N] = {0};



void dfs(int v, int p) {
    // par[v][bit][0]
    dep[v] = 1 + dep[p];
    tin[v] = timer++;
    int fact = 1;
    for(int bit=0;bit<M;bit++) {
        if(a[p]&fact) par[v][bit][0] = p;
        else par[v][bit][0] = par[p][bit][0];
        for(int pow=1;pow<K;pow++) {
            par[v][bit][pow] = par[par[v][bit][pow-1]][bit][pow-1];
        }
        fact = fact<<1;
    }
    par2[v][0] = p;
    for(int pow=1;pow<K;pow++) par2[v][pow] = par2[par2[v][pow-1]][pow-1];
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
    tout[v] = timer++;
}

bool isAncesstor(int v, int u) {
    return tin[v]<=tin[u] && tout[v]>=tout[u];
}

int lca(int a, int b) {
    if(isAncesstor(a, b)) return a;
    for(int j=K-1;j>=0;j--) {
        if(!isAncesstor(par2[a][j], b)) a = par2[a][j];
    }
    return par2[a][0];
}


pair<int, int> bLift(int v, int l, int bit) {
    int newV = v;
    int fact = (1<<bit);
    if(!(a[v]&fact)) newV = par[v][bit][0];
    if(!isAncesstor(l, newV)) return {0, 0};
    // if(!isAncesstor(l, par[newV][bit][0])) return {newV, dep[newV]-dep[v]};
    for(int j=K-1;j>=0;j++) if(isAncesstor(l, par[newV][bit][j])) newV = par[newV][bit][j];
    return {a[newV], dep[newV]-dep[v]};
}


// (a, distance from v)
pair<pair<int, int>, pair<int, int>> getFirstElForBit(int u, int v, int bit) {
    int l = lca(u, v);
    // getting for u
    int fact = (1<<bit);
    pair<int, int> p1 = {0, 0}, p2 = {0, 0};
    if(a[u]&fact) {
        p1 = {a[u], 0};
    }
    if(p1!=make_pair(0, 0)) {
        int x = par[u][bit][0];
        if(isAncesstor(l, x)) p1 = {a[x], dep[x]-dep[u]};
        else {
            auto p = bLift(v, l, bit);
            if(p!=make_pair(0, 0)) {
                p1.first = p.first;
                p1.second = dep[l] - dep[u] + dep[l] - dep[v] - p.second;
            }
        }
    }
    if(p1==make_pair(0, 0)) return {{0, 0}, {0, 0}};
    if(a[v]&fact) {
        p2 = {a[v], dep[l] - dep[u] + dep[l] - dep[v]};
    }
    if(p2!=make_pair(0, 0)) {
        int x = par[v][bit][0];
        if(isAncesstor(l, x)) p2 = {a[x], dep[l]-dep[u]+dep[l]-dep[x]};
        else {
            auto p = bLift(u, l, bit);
            if(p!=make_pair(0, 0)) {
                p2.first = p.first;
                p2.second = p.second;
            }
        }
    }

    return {p1, p2};
}


 
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    

    timer = 0;
    dfs(1, 0);

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/