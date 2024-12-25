/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 23:39:25
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)5e4+10;

int dp[MAXN][3];

int n, x;
int a[MAXN];

void maximize(int &x, int y) {
    x = max(x, y);
}
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> x;

    for(int i=0;i<=n;i++) for(int j=0;j<3;j++) dp[i][j] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) maximize(dp[i+1][0], dp[i][j]);
        maximize(dp[i+1][1], dp[i][0]+1);
        if(i>0 && a[i]+a[i-1]>=2*x) maximize(dp[i+1][2], dp[i][1]+1);
        if(i>1 && a[i]+a[i-1]>=2*x && a[i]+a[i-1]+a[i-2]>=3*x) maximize(dp[i+1][2], dp[i][2]+1); 
    }

    int ans = 0;
    for(int i=0;i<3;i++) maximize(ans, dp[n][i]);

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