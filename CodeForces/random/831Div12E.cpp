/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jul, 2024 | 15:54:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5)+10;

vector<int> g[MAXN];
int dep[MAXN];
int n, p;


int dfs(int v) {
    dep[v] = 1;
    int mx = 0;
    int res = 0;
    for(int u: g[v]) {
        res += dfs(u);
        mx = max(mx, dep[u]);
    }
    dep[v] += mx;
    return max(res, dep[v]);
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=1;i<n;i++) {
        cin >> p, p--;
        g[p].push_back(i);
    }

    cout << dfs(0) << "\n";




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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/