/**
*   author: lazyhash(yashkundu)
*   created: 04 Mar, 2024 | 18:13:25
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e3+5;
vector<int> g[N];
int a[N];
 
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }


    // simulating the first n rounds
    for(int t=1;t<=n;t++) {
        // get S: {x, ax>0}
    }

    
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