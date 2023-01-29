/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jan, 2023 | 09:21:41
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


const int N = 2e5+10;

vector<int> g[N], gT[N];
vector<bool> vis(N);
vector<pair<pair<int, int>, int>> edges;
vector<int> reachable(N, 0);
int n, m;



void dfs(int v, int& root) {
    vis[v] = true;
    for(int u: g[v]) {
        if(vis[u]) continue;
        dfs(u, root);
    }
    // vertex with the maximum tout, the only possible resuls
    root = v;
}

int cnt(int v) {
    int num = 1;
    if(vis[v]) return 0;
    vis[v] = true;
    for(int u: g[v]) {
        num += cnt(u);
    }
    return num;
}


bool check(int x) {
    for(int i=1;i<=n;i++) g[i].clear();
    fill(vis.begin(), vis.begin()+n+1, false);
    for(int i=0;i<int(edges.size());i++) {
        int u = edges[i].first.first, v = edges[i].first.second;
        g[u].push_back(v);
        if(i<x) g[v].push_back(u);
    }

    int root = 0;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i, root);

    // root
    fill(vis.begin(), vis.begin()+n+1, false);
    return cnt(root)==n;
}
 
void solve() {
    
    cin >> n >> m;
    edges.clear();
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }


    sort(edges.begin(), edges.end(), [] (pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
        return p1.second<p2.second;
    });


    // e0 e1 e2 e3 e4 e5 e6 e7 -----------
    int l = 0, r = m+1;
    while(l<r) {
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    int ans = -1;
    if(l==0) ans = 0;
    else if(l<=m) ans = edges[l-1].second;

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