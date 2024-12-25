/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jun, 2024 | 19:28:01
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 3e5+1;
const int MAXK = 11;
const ll inf = 1e18+5;

ll dp[MAXN][MAXK];
ll a[MAXN];
ll pref[MAXN];

int n, k;
 
void solve() {
    cin >> n >> k;
    k = min(k, n-1);
    
    pref[0] = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }

    for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = inf;
    dp[0][0] = 0;

    ll mnVal = inf;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=k;j++) {
            if(dp[i][j]==inf) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i]);
            for(int l=1;l<=min(k-j, n-i);l++) {
                mnVal = inf;
                if(i+l<n) mnVal = min(mnVal, a[i+l]);
                if(i>0) mnVal = min(mnVal, a[i-1]);
                dp[i+l][j+l] = min(dp[i+l][j+l], dp[i][j] + mnVal*(l));
            }
        }
    }

    ll ans = inf;
    for(int i=0;i<=k;i++) ans = min(ans, dp[n][i]);

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/