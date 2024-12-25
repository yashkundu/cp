/**
*    author:  lazyhash(yashkundu)
*    created: 03 Nov, 2024 | 12:55:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 105;

int dp[MAXN][MAXN];

int n;
vector<vector<int>> a;
 
void solve() {
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) {
        a[i].resize(n);
        for(int j=0;j<n;j++) cin >> a[i][j];
    }


    for(int i=0;i<n;i++) dp[0][i] = a[0][i];

    for(int i=1;i<n;i++) {
        for(int j=0;j<n;j++) {
            dp[i][j] = dp[i-1][j];
            if(j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            if(j<n-1) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
            dp[i][j] += a[i][j];
        }
    }

    int ans = (int)1e9+10;


    for(int i=0;i<n;i++) ans = min(ans, dp[n-1][i]);

    cout << ans << "\n";



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