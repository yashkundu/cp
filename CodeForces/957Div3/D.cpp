/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 20:27:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+20;
const int inf = int(1e9)+10;

int dp[MAXN];

int n, m, k;
string s;
 
void solve() {
    cin >> n >> m >> k;
    for(int i=0;i<=n+1;i++) dp[i] = inf;
    dp[0] = 0;

    cin >> s;

    for(int i=0;i<=n;i++) {
        if(dp[i]==inf) continue;
        if(i==0 || s[i-1]=='L') {
            for(int j=i+1;j<=i+m;j++) {
                dp[j] = min(dp[j], dp[i]);
            }
        }
        if(i!=0 && s[i-1]=='W') {
            dp[i+1] = min(dp[i+1], dp[i]+1);
        }
    }

    if(dp[n+1]<=k) cout << "YES\n";
    else cout << "NO\n";


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