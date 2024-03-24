/**
*   author: lazyhash(yashkundu)
*   created: 09 Jan, 2024 | 12:02:42
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

const int N = 5e5+10;
int a[N];
vector<int> g[N];
ll dp[N];
ll ans = 0;



void dfs(int v, int p) {
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }

    vector<ll> childVals;
    for(int u: g[v]) if(u!=p) childVals.push_back(dp[u]);
    sort(childVals.rbegin(), childVals.rend());

    // we delete all of v's children
    dp[v] = a[v];
    // chose exactly one vertex, then we won't count a[v]
    if(childVals.size()>=1) {
        dp[v] = max(dp[v], childVals[0]);
    }

    // chose >=2 values
    if(childVals.size()>=2) {
        ll sum = 0;
        for(int i=0;i<childVals.size();i++) {
            if(i>1 && childVals[i]<0) break;
            sum += childVals[i];
        }
        dp[v] = max(dp[v], a[v] + sum);
    }

    // calculating contribution to the ans, if we remove the edge to the ancesstor
    // delete all the child
    ans = max(ans, 1LL*a[v]);
    // keep one child
    if(childVals.size()>=1) ans = max(ans, a[v]+childVals[0]);
    // keep two child
    if(childVals.size()>=2) ans = max(ans, childVals[0]+childVals[1]);
    // keep >=3 child
    if(childVals.size()>=3) {
        ll sum = 0;
        for(int i=0;i<childVals.size();i++) {
            if(i>2 && childVals[i]<0) break;
            sum += childVals[i];
        }
        ans = max(ans, a[v] + sum);
    } 

}


 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) g[i].clear();
    ans = 0;

    for(int i=0;i<n-1;i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

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