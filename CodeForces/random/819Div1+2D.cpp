/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jul, 2024 | 23:47:37
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;

int n, m;
vector<pair<int, int>> g[MAXN];
bool edges[MAXN];
int dep[MAXN];
int par[MAXN];
bool vis[MAXN]; 

int u[MAXN], v[MAXN];

set<int> st;

void dfs(int v) {
    vis[v] = 1;
    for(auto [u, e]: g[v]) {
        if(vis[u]) continue;
        edges[e] = 1;
        dep[u] = 1 + dep[v];
        par[u] = e;
        dfs(u);
    }
}


void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<m;i++) {
        cin >> u[i] >> v[i], u[i]--, v[i]--;
        g[u[i]].push_back({v[i], i});
        g[v[i]].push_back({u[i], i});
    }

    fill(vis, vis+n, 0);
    fill(edges, edges+m, 0);
    dep[0] = 0;
    par[0] = -1;

    dfs(0);

    st.clear();

    for(int i=0;i<m;i++) if(!edges[i]) st.insert(u[i]), st.insert(v[i]);


    if(m==n+2 && st.size()==3) {
        int a = *st.begin(), b = *next(st.begin());
        if(dep[b]<dep[a]) swap(a, b);
        edges[par[b]] = 0;
        for(int i=0;i<m;i++) {
            if(make_pair(min(u[i], v[i]), max(u[i], v[i]))==make_pair(min(a, b), max(a, b))) edges[i] = 1;
        }
    }

    for(int i=0;i<m;i++) cout << (edges[i]?'1':'0');
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