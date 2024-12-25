/**
*    author:  lazyhash(yashkundu)
*    created: 09 Nov, 2024 | 21:01:18
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)3e5+10;

int n;
int a[MAXN], dp[MAXN][3];

void minimize(int &x, int y) {
    x = min(x, y);
}

int calc(int x, int y) {
    if(x<y) return x+1;
    else if(x>y) return x-1;
    return x;
}
 
void solve() {
    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=0;i<=n;i++) for(int j=0;j<3;j++) dp[i][j] = -n;


    dp[0][0] = 0;


    for(int i=1;i<=n;i++) {
        dp[i][0] = calc(dp[i-1][0], a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][2] = max(calc(dp[i-1][1], a[i]), calc(dp[i-1][2], a[i]));
    }


    int ans = max(dp[n][1], dp[n][2]);

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