/**
*   author: lazyhash(yashkundu)
*   created: 07 May, 2024 | 09:18:14
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

const int N = 3e5+10;
vector<int> g[N];
int dp1[N];
pair<int, int> dp2[N];
pair<pair<int, int>, pair<int, int>> dp[N];
int ans;


void dfs0(int v, int p) {
    int numChilds = g[v].size() - (p==-1?0:1);
    int child1 = -1, f1 = 0, child2 = -1, f2 = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs0(u, v);
        if(dp1[u]>=f1) {
            f2 = f1;
            child2 = child1;
            f1 = dp1[u];
            child1 = u;
        } else if(dp1[u]>f2){
            f2 = dp1[u];
            child2 = u;
        }
    }
    dp2[v] = {child1, child2};
    if(child1==-1) dp1[v] = 1;
    else dp1[v] = dp1[child1] + numChilds;
}

void dfs1(int v, int p) {
    for(int u: g[v]) {
        if(u==p) continue;
        // v -> u
        int oldV = dp1[v];
        int oldU = dp1[u];
        pair<int, int> oldP = dp2[u];
        // changing
        if(dp2[v].first==u) {
            if(dp2[v].second==-1) dp1[v] = 1;
            else dp1[v] = dp1[dp2[v].second] + g[v].size() - 1;
        } else {
            dp1[v]--;
        }
        if(dp2[u].first==-1 || dp1[v]>=dp1[dp2[u].first]) {
            dp2[u].second = dp2[u].first;
            dp2[u].first = v;
        } else if(dp2[u].second==-1 || dp1[v]>dp1[dp2[u].second]) {
            dp2[u].second = v;
        }
        dp1[u] = dp1[dp2[u].first] + g[u].size();
        ans = max(ans, dp1[u]);
        dfs1(u, v);
        dp1[v] = oldV;
        dp1[u] = oldU;
        dp2[u] = oldP;
    }
}


int n;

void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n;i++) dp2[i] = {-1, -1};

    for(int i=0;i<n-1;i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    dfs0(0, -1);
    ans = dp1[0];
    dfs1(0, -1);

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/