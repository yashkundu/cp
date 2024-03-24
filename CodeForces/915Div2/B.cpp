/**
*   author: lazyhash(yashkundu)
*   created: 25 Dec, 2023 | 10:25:10
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

int deg[N] = {0};
 
void solve() {
    int n;
    cin >> n;
    fill(deg, deg+n+1, 0);

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }

    int numLeaves = 0;
    for(int i=1;i<=n;i++) if(deg[i]==1) numLeaves++;
    int ans = (numLeaves+1)/2;
    if(numLeaves==1) ans = 0;
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