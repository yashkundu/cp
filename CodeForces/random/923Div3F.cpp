/**
*    author:  lazyhash(yashkundu)
*    created: 25 Jun, 2024 | 16:32:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MAXN = 2e5+10;

int par[MAXN], rnk[MAXN];
bool vis[MAXN];

int find(int v) {
    if(par[v]==v) return v;
    return par[v] = find(par[v]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(rnk[a]>rnk[b]) swap(a,b);
    par[a] = b;
    if(rnk[a]=rnk[b]) rnk[b]++;
    return true;
}

int n, m;
vector<pair<int, pair<int, int>>> edges;
vector<int> g[MAXN];

int u, v, w;
vector<int> path;


bool dfs(int v, int x) {
    vis[v] = 1;
    if(v==x) {
        path.push_back(x);
        return true;
    }
    for(int u: g[v]) {
        if(vis[u]) continue;
        if(dfs(u, x)) {
            path.push_back(v);
            return true;
        }
    }
    return false;
}


 
void solve() {
    cin >> n >> m;

    for(int i=0;i<n;i++) g[i].clear();
    fill(rnk, rnk+n, 0);
    fill(vis, vis+n, 0);
    iota(par, par+n, 0);
    edges.clear();
    path.clear();

    for(int i=0;i<m;i++) {
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, {u, v}});
    }

    sort(edges.rbegin(), edges.rend());

    int ind = -1;

    for(int i=0;i<edges.size();i++) {
        w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
        if(!merge(u, v)) {
            ind = i;
        }
    }

    for(int i=0;i<ind;i++) {
        u = edges[i].second.first, v = edges[i].second.second;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // debug(g[0], g[1], g[2], g[3], g[4], g[5]);


    u = edges[ind].second.first, v = edges[ind].second.second;

    // debug(u, v);

    dfs(u, v);


    cout << edges[ind].first << " " << path.size() << "\n";
    for(int x: path) cout << x+1 << " ";
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