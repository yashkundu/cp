/**
*   author: lazyhash(yashkundu)
*   created: 27 Sep, 2023 | 09:15:10
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
vector<int> g[N];
vector<int> a(N);
vector<int> cntV(N);
int n;



void dfs1(int v, int p, ll &ans) {
    int cnt = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs1(u, v, ans);
        cnt += cntV[u];
    }
    int xorrer = (p==-1)?a[v]:a[p];
    cntV[v] = cnt;
    ans += 1LL*(a[v]^xorrer)*cnt;
}


void dfs2(int v, int p, ll curVal, vector<ll> &res) {
    res[v] = curVal;
    for(int u: g[v]) {
        if(u==p) continue;
        ll newVal = curVal - 1LL*(a[u]^a[v])*cntV[u];
        cntV[v] = n - cntV[u];
        cntV[u] = n;
        newVal += 1LL*(a[u]^a[v])*cntV[v];
        dfs2(u, v, newVal, res);
        cntV[u] = n - cntV[v];
        cntV[v] = n;
    }
    
}



 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    fill(cntV.begin(), cntV.begin()+n, 0);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // calculating ans by rooting 0th vertex

    ll ans = 0;
    dfs1(0, -1, ans);


    // calculating ans for all other roots by rerooting the tree
    vector<ll> res(n, 0);
    dfs2(0, -1, ans, res);

    for(int i=0;i<n;i++) {
        cout << res[i] << " ";
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