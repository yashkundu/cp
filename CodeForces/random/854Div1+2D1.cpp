/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 12:40:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(5e3)+10;

const ll inf = ll(1e18) + 10000;

int n, k;
int a[MAXN];

ll dp[MAXN][MAXN];
ll cold[MAXN], hot[MAXN];

void minimize(ll &x, ll y) {
    x = min(x, y);
}

ll ans = 0;
 
void solve() {
    cin >> n >> k;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=k;i++) cin >> cold[i];
    for(int i=1;i<=k;i++) cin >> hot[i];

    a[0] = 0;
    for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = inf;
    dp[0][0] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=k;j++) {
            if(dp[i][j]==inf) continue;
            minimize(dp[i+1][j], dp[i][j] + (a[i]==a[i+1]?hot[a[i+1]]:cold[a[i+1]]));
            minimize(dp[i+1][a[i]], dp[i][j] + (a[i+1]==j?hot[a[i+1]]:cold[a[i+1]]));
        }
    }

    ans = inf;
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