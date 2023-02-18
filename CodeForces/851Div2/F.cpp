/**
*    author:  lazyhash(yashkundu)
*    created: 18 Feb, 2023 | 09:28:56
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 250010;
int n, q, k;
int edges[N][2];
vector<int> col(N, -1);
vector<int> val(N, 0);
vector<int> b(N, 0);
vector<pair<int, int>> g[N];

void dfs(int v) {
    col[v] = k;
    for(auto [u, w]: g[v]) {
        int new_val = b[v]^w;
        if(col[u]==-1) {
            b[u] = new_val;
            dfs(u);
        } else if(b[u]!=new_val) {
            cout << "No\n";
            exit(0);
        }
    }
}
 
 
void solve() {
    int n, q;
    cin >> n >> q;

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<2;j++) {
            cin >> edges[i][j];
            edges[i][j]--;
        }
    }

    while(q--) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    for(int i=0;i<n;i++) if(col[i]==-1) {
        dfs(i);
        k++;
    }
    int tot = 0;
    for(int i=0;i<n-1;i++) {
        int u = edges[i][0], v = edges[i][1];
        val[col[u]] ^= 1;
        val[col[v]] ^= 1;
        tot ^= (b[u]^b[v]);
    }

    for(int i=0;i<k;i++) {
        if(val[i]==0) continue;
        val[i] = tot;
        tot = 0;
    }

    cout << "Yes\n";

    for(int i=0;i<n-1;i++) {
        int u = edges[i][0], v = edges[i][1];
        cout << (b[u]^b[v]^val[col[u]]^val[col[v]]) << " ";
    }
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