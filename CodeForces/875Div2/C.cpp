/**
*   author: lazyhash(yashkundu)
*   created: 30 May, 2023 | 22:40:52
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
vector<pair<int, int>> g[N];



int dfs(int v, int p=-1, int pEdge=N, int curAns=0) {
    int ans = curAns;
    for(auto [u, ind]: g[v]) {
        if(u==p) continue;
        ans = max(ans, dfs(u, v, ind, curAns+((ind<pEdge)?1:0)));
    }
    return ans;
}


 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    dfs(0);

    cout << dfs(0) << "\n";



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