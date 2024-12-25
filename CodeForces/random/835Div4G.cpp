/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jul, 2024 | 15:11:30
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5)+10;

vector<pair<int, int>> g[MAXN];

int n, a, b;
int u, v, w;


void dfs(int v, int p, int x, set<int> &st) {
    for(auto [u, w]: g[v]) {
        if(u==p || u==b) continue;
        st.insert(x^w);
        dfs(u, v, x^w, st);
    }
}
 
void solve() {
    cin >> n >> a >> b, a--, b--;

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        cin >> u >> v >> w, u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    set<int> sa;
    dfs(a, -1, 0, sa);
    sa.insert(0);

    set<int> sb;
    dfs(b, -1, 0, sb);

    for(int x: sa) {
        if(sb.find(x)!=sb.end()) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";




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