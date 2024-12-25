/**
*    author:  lazyhash(yashkundu)
*    created: 22 Nov, 2024 | 20:00:07
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll inf = (ll)1e18+10;

int n, a, b;
vector<vector<ll>> dp;




void solve() {
    cin >> n >> a >> b;

    int x = n, y = n;

    while(gcd(x, a)!=1) x--;
    while(gcd(y, b)!=1) y--;


    ll ans = 0;
    for(int i=1;i<=x;i++) ans += gcd(i, a);
    for(int j=1;j<=y;j++) ans += gcd(j, b);

    ans += (x-1) + (y-1);


    int dx = n - x, dy = n-y;
    dp.resize(dx+1);
    for(int i=0;i<=dx;i++) {
        dp[i].resize(dy+1);
        for(int j=0;j<=dy;j++) dp[i][j] = 0;
    }



    for(int i=0;i<=dx;i++) {
        for(int j=0;j<=dy;j++) {
            if(i+j==0) {
                dp[i][j] = ans;
                continue;
            }
            dp[i][j] = inf;
            if(i>0) dp[i][j] = dp[i-1][j] + gcd(x+i, a) + gcd(y+j, b);
            if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1] + gcd(x+i, a) + gcd(y+j, b));
        }
    }

    cout << dp[dx][dy] << "\n";








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