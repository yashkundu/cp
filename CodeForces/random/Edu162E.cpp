/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jun, 2024 | 20:25:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5+10;

int c[MAXN];
vector<int> g[MAXN];
map<int, int> cnt[MAXN];

int n, u, v;

ll ans = 0;



void dfs(int v, int p = -1) {
    int bst = -1;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        if(bst==-1 || cnt[bst].size()<cnt[u].size()) bst = u;
    }

    for(int u: g[v]) {
        if(u==p || u==bst) continue;
        for(auto it: cnt[u]) {
            int x = it.first, y = it.second;
            if(x!=c[v]) ans += 1LL*cnt[bst][x]*y;
            cnt[bst][x] += y;
        }
    }

    if(bst!=-1) swap(cnt[bst], cnt[v]);
    ans += cnt[v][c[v]];
    cnt[v][c[v]] = 1;
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear(), cnt[i].clear();

    for(int i=0;i<n;i++) cin >> c[i];

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans = 0;
    dfs(0);

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