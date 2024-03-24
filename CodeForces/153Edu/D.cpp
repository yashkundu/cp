/**
*   author: lazyhash(yashkundu)
*   created: 28 Aug, 2023 | 22:53:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

const int N = 105;
int dp[2][N][N*N];

const int inf = 1e9+10;


void solve() {
    string s;
    cin >> s;
    int n = s.size();

    for(int i=0;i<=n;i++) for(int j=0;j<=i*i;j++) dp[0][i][j] = inf;
    dp[0][0][0] = 0;


    for(int i=0;i<n;i++) {
        int par = i&1;
        for(int j=0;j<=i+1;j++) for(int k=0;k<=j*(i+1-j);k++) dp[par^1][j][k] = inf;
        for(int j=0;j<=i;j++) {
            for(int k=0;k<=j*(i-j);k++) {
                if(dp[par][j][k]==inf) continue;
                // we add zero at (i+1)th index
                dp[par^1][j+1][k] = min(dp[par^1][j+1][k], dp[par][j][k] + (s[i]!='0'));
                // we add one at (i+1)th index
                dp[par^1][j][k+j] = min(dp[par^1][j][k+j], dp[par][j][k] + (s[i]!='1'));
            }
        }
    }

    int cnt0 = count(s.begin(), s.end(), '0');


    int ans = dp[n&1][cnt0][cnt0*(n-cnt0)/2]/2;

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/