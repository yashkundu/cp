/**
*    author:  lazyhash(yashkundu)
*    created: 28 Sep, 2024 | 14:33:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)5e5+10;

vector<int> g[MAXN];
int dep[MAXN], deg[MAXN], par[MAXN], below[MAXN], cnt[MAXN];

vector<pair<int, int>> leaves;

int n;
int u, v;

int ans = 0;


void dfs(int v, int p = -1, int d = 0) {
    par[v] = p;
    dep[v] = d;
    cnt[v] = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v, d+1);
        cnt[v] += cnt[u];
    }
    below[d] += cnt[v] - 1;
}

 
void solve() {
    cin >> n;
    for(int i=0;i<=n;i++) {
        g[i].clear();
        dep[i] = deg[i] = par[i] = below[i] = 0;
    }
    leaves.clear();

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
        deg[u]++, deg[v]++;
    }



    dfs(0);
    for(int i=1;i<n;i++) {
        if(deg[i]==1) leaves.push_back({dep[i], i});
    }

    sort(leaves.begin(), leaves.end());

    ans = n-1;

    int ptr = 0;
    int rem = 0;

    for(int i=1;i<=n;i++) {
        while(ptr<leaves.size() && leaves[ptr].first<i) {
            int v = leaves[ptr].second;
            while(v && deg[v]==1) {
                rem++;
                deg[par[v]]--;
                v = par[v];
            }
            ptr++;
        }
        ans = min(ans, below[i] + rem);
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