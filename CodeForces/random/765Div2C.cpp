/**
*    author:  lazyhash(yashkundu)
*    created: 08 Oct, 2024 | 20:06:28
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAXN = (int)505;
const int inf = (int)1e9+10;

int dp[MAXN][MAXN];
int n, l, rem;

int d[MAXN], a[MAXN];
 
void solve() {
    cin >> n >> l >> rem;

    d[n] = l;
    for(int i=0;i<n;i++) cin >> d[i];
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<=n;i++) for(int j=0;j<=n+1;j++) dp[i][j] = inf;

    dp[0][1] = 0;


    for(int i=0;i<n;i++) {
        for(int j=1;j<=i+1;j++) {
            if(dp[i][j]==inf) continue;
            for(int k=i+1;k<=n;k++) {
                dp[k][j+1] = min(dp[k][j+1], dp[i][j] + a[i]*(d[k]-d[i]));
            }
        }
    }

    int ans = inf;
    for(int i=n+1;i>=(n+1-rem);i--) ans = min(ans, dp[n][i]);

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