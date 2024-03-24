/**
*   author: lazyhash(yashkundu)
*   created: 06 Feb, 2024 | 09:21:30
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

set<pair<int, int>> guns[2];
 
void solve() {
    int n, m;
    cin >> n >> m;

    guns[0].clear();
    guns[1].clear();
    
    int r;
    cin >> r;

    for(int i=0;i<r;i++) {
        int t, d, coord;
        cin >> t >> d >> coord;
        d--;
        guns[d].emplace(coord, t);
    }

    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(m+1, vector<bool>(r+1, 0)));
    // dp[i][j][k] - is it possible to reach (i, j) with k stops in between
    dp[0][0][0] = 1;


    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            for(int k=0;k<=r;k++) {
                // check if the current state is non reachable
                int totTime = i+j+k;
                if(guns[0].count({i, totTime}) | guns[1].count({j, totTime})) continue;
                if(k>0) dp[i][j][k] = dp[i][j][k] || dp[i][j][k-1];
                if(i>0) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k];
                if(j>0) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k];
            }
        }
    }

    int minStops = -1;
    for(int i=0;i<=r;i++) {
        if(dp[n][m][i]) {
            minStops = i;
            break;
        }
    }

    int ans = -1;
    if(minStops!=-1) ans = n+m+minStops;

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