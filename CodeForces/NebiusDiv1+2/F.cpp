/**
*   author: lazyhash(yashkundu)
*   created: 19 Mar, 2023 | 21:59:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
vector<pair<int, int>> g[N];
vector<int> dis(N, -1);
int n, m, q;


int getEc(int query) {
    fill(dis.begin(), dis.begin()+n, -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    int e = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto [v, t]: g[u]) {
            if(t>query || dis[v]!=-1) continue;
            dis[v] = 1 + dis[u];
            e = dis[v];
            q.push(v);
        }
    }
    return e;
}
 
void solve() {
    cin >> n >> m >> q;

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, 0);
    }

    for(int i=1;i<=q;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    vector<int> ans(q+1, 0);
    
    for(int i=0;i<=q;) {
        ans[i] = getEc(i);
        // i+1 - q, 
        int l =  i+1, r = q;
        while(r-l>0) {
            int mid = l + (r-l+1)/2;
            if(2*getEc(mid)>=ans[i]) l = mid;
            else r = mid - 1;
        }
        int j = i + 1;
        while(j<q+1 && j<l+1) ans[j++] = ans[i];
        i = j;
    }

    for(int i=0;i<=q;i++) cout << ans[i] << " ";
    cout << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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