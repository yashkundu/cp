/**
*   author: lazyhash(yashkundu)
*   created: 24 Mar, 2024 | 16:16:55
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 4e5 + 10;
vector<int> g[N], gT[N];
bool vis[N];
int cnt[N];


vector<int> multiV;
vector<int> infiV;
vector<int> order;


int n, m;


void dfs1(int v) {
    vis[v] = 1;
    cnt[v] = 1;
    for(int u: g[v]) {
        if(vis[u]) {
            multiV.push_back(u);
            continue;;
        }
        dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v) {
    vis[v] = 1;
    cnt[v] = 2;
    for(int u: g[v]) {
        if(vis[u]) continue;
        dfs2(u);
    }
}


void dfs3(int v, vector<int> &scc) {
    vis[v] = 1;
    scc.push_back(v);
    for(int u: gT[v]) {
        if(vis[u] || !cnt[u]) continue;
        dfs3(u, scc);
    }
}


void dfs4(int v) {
    vis[v] = 1;
    cnt[v] = 3;
    for(int u: g[v]) {
        if(vis[u]) continue;
        dfs4(u);
    }
}


 
void solve() {
    cin >> n >> m;

    for(int i=0;i<n;i++) g[i].clear(), gT[i].clear();
    fill(vis, vis+n, 0);
    fill(cnt, cnt+n, 0);

    multiV.clear();
    infiV.clear();
    order.clear();


    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        gT[b].push_back(a);
        if(a==b) infiV.push_back(a);
    }

    

    dfs1(0);

    fill(vis, vis+n, 0);
    for(int x: multiV) if(!vis[x]) dfs2(x);


    for(int i=0;i<order.size()/2;i++) swap(order[i], order[order.size()-1-i]);
    fill(vis, vis+n, 0);

    vector<int> scc;

    for(int v: order) {
        if(vis[v]) continue;
        scc.clear();
        dfs3(v, scc);
        if(scc.size()>1) infiV.push_back(v);
    }

    fill(vis, vis+n, 0);
    for(int x: infiV) {
        if(!cnt[x] || vis[x]) continue;
        // run dfs
        dfs4(x);
    }


    for(int i=0;i<n;i++) {
        if(cnt[i]==3) cnt[i] = -1;
        cout << cnt[i] << " ";
    }

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/