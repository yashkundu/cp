/**
*   author: lazyhash(yashkundu)
*   created: 19 Feb, 2024 | 11:55:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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

const int N = 2e5+10;
vector<int> g[N], gT[N];
ll a[N];
int scc[N], sccSize[N];
bool vis[N];
vector<int> ord;
vector<pair<int, int>> gC[N], gCT[N];

// dp[i] -> the lenght of the longest simple path ending at i along with it's least value sig(a[i])
pair<int, ll> dp[N];


void dfs1(int v) {
    if(vis[v]) return;
    vis[v] = 1;
    for(int u: g[v]) dfs1(u);
    ord.push_back(v);
}


void dfs2(int v, vector<int> &components) {
    if(vis[v]) return;
    vis[v] = 1;
    components.push_back(v);
    for(int u: gT[v]) dfs2(u, components);
}


void dfs3(int v) {
    if(vis[v]) return;
    vis[v] = 1;
    for(auto [u, w]: gC[v]) dfs3(u);
    ord.push_back(v);
}



 
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear(), gT[i].clear(), gC[i].clear(), gCT[i].clear();

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        gT[v].push_back(u);
    }

    vector<vector<int>> gVec(g, g+n);
    vector<vector<int>> gTVec(gT, gT+n);
    
    // debug(gVec);
    // debug(gTVec);

    fill(vis, vis+n, 0);
    ord.clear();
    for(int i=0;i<n;i++) dfs1(i);

    // debug("ordered according to tout: ", ord);

    fill(vis, vis+n, 0);
    for(int i=0;i<n;i++) scc[i] = i;
    fill(sccSize, sccSize+n, 1);
    vector<int> components;
    for(auto it = ord.rbegin(); it!=ord.rend(); it++) {
        int v = *it;
        if(vis[v]) continue;
        components.clear();
        dfs2(v, components);
        int first = components.front();
        for(int i=1;i<components.size();i++) {
            a[first] += a[components[i]];
            scc[components[i]] = first;
        }
        sccSize[first] = components.size();
    }

    vector<int> sccVec(scc, scc+n);
    vector<int> sccSizeVec(sccSize, sccSize+n);
    // debug(sccVec);
    // debug(sccSizeVec);

    for(int v=0;v<n;v++) {
        for(int u: g[v]) {
            int root_v = scc[v], root_u = scc[u];
            if(root_v==root_u) continue;
            gC[root_v].emplace_back(root_u, sccSize[root_u]);
            gCT[root_u].emplace_back(root_v, sccSize[root_u]);
        }
    }

    for(int i=0;i<n;i++) {
        int root_i = scc[i];
        if(gCT[root_i].empty()) {
            gC[n].emplace_back(root_i, sccSize[root_i]);
            gCT[root_i].emplace_back(n, sccSize[root_i]);
        }
    }

    // debug(gC);
    ord.clear();
    fill(vis, vis+n, 0);
    for(int i=0;i<n;i++) dfs3(scc[i]);

    vector<int> tpOrd(ord.rbegin(), ord.rend());


    // debug(tpOrd);
    // debug(gC[])


    for(int v: tpOrd) {
        dp[v] = {0, -a[v]};
        for(auto [u, w]: gCT[v]) {
            pair<int, ll> p = {dp[u].first+w, dp[u].second-a[v]};
            dp[v] = max(dp[v], p);
        }
    }

    pair<int, ll> ans = {0 ,0};

    for(int i=0;i<n;i++) ans = max(ans, dp[i]);

    cout << ans.first << " " << -ans.second << "\n";


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