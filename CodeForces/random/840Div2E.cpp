/**
*   author: lazyhash(yashkundu)
*   created: 29 Feb, 2024 | 09:43:18
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
// dp[i] - the minimum number of nodes needed to create an i-reachable graph
int dp[N] = {0};
const int inf = 1e9;

void solve() {
    int p;
    cin >> p;

    for(int i=1;i<=p;i++) dp[i] = inf;

    // iterating over number of bidirectional node pairs
    for(int i=1;i<=p;i++) {
        // iterate on last cycle length
        for(int j=2;j*(j-1)/2<=i;j++) {
            dp[i] = min(dp[i], dp[i-j*(j-1)/2]+j);
        }
    }

    cout << dp[p] << " " << (1LL*dp[p]*(dp[p]-1)/2 - p) << "\n";

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