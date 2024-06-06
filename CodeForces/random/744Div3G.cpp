/**
*   author: lazyhash(yashkundu)
*   created: 28 Apr, 2024 | 21:56:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e4+5;
const int M = 1e3+5;

const int inf = 1e9+10;

int dp[N][2*M];
int a[N];

int n;


void minimize(int &num, int x) {
    num = min(num, x);
}

 
void solve() {
    cin >> n;

    for(int i=0;i<=n;i++) for(int j=0;j<=2*M;j++) dp[i][j] = inf;

    dp[0][0] = 0;
    
    for(int i=0;i<n;i++) cin >> a[i];



    for(int i=0;i<n;i++) {
        for(int j=0;j<=2*M;j++) {
            if(dp[i][j]==inf) continue;
            // place a[i]
            // a[i] is placed in the left orientation
            minimize(dp[i+1][max(0, j-a[i])], dp[i][j] + a[i]);
            // a[i] is placed to the right
            if(j+a[i]<2*M) {
                minimize(dp[i+1][j+a[i]], max(0, dp[i][j]-a[i]));
            }
        }
    }

    int ans = inf;
    for(int l=0;l<2*M;l++) {
        ans = min(ans, l + dp[n][l]);
    }

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