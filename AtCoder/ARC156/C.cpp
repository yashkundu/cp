/**
*   author: lazyhash(yashkundu)
*   created: 25 Feb, 2023 | 17:44:53
**/
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 5010;
vector<int> g[N];
vector<int> deg(N, 0);

void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    vector<int> p(n, -1);

    queue<int> q;
    for(int i=0;i<n;i++) if(deg[i]==1) q.push(i);

    while(!q.empty()) {
        if(q.size()>1) {
            int u = q.front();
            q.pop();
            int v = q.front();
            q.pop();
            for(int x: g[u]) {
                deg[x]--;
                if(deg[x]==1) q.push(x);
            }
            for(int x: g[v]) {
                deg[x]--;
                if(deg[x]==1) q.push(x);
            }
            p[u] = v;
            p[v] = u;
        } else {
            int u = q.front();
            q.pop();
            p[u] = u;
        }
    }

    for(int i=0;i<n;i++) cout << (p[i]+1) << " ";
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