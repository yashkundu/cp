/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jan, 2023 | 21:17:17
**/
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

 
void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<ll> dp(n+1, 1e18);
    dp[1] = 0;

    int k = sqrt(n) +1;
    vector<int> last(k, 0);

    if(a[1]<k) last[a[1]] = 1;

    for(int i=2;i<=n;i++) {
        if(a[i]>=k) {
            int mn = a[i];
            for(int j=i-1;j>=max(1, i-k); j--) {
                mn = min(mn, a[j]);
                dp[i] = min(dp[i], dp[j] + (ll)mn*(i-j)*(i-j));
            }
        } 
        if(a[i]<k) {
            for(int j=i-1;j>=1;j--) {
                dp[i] = min(dp[i], dp[j] + (ll)a[i]*(i-j)*(i-j));
                if(a[j]<=a[i]) break;
            }
        }
        for(int j=min(k-1, a[i]-1); j>=1; j--) {
            if(last[j]) {
                dp[i] = min(dp[i], dp[last[j]] + (ll)j*(i-last[j])*(i-last[j]));
            }
        }
        if(a[i]<k) last[a[i]] = i;
    }

    for(int i=1;i<=n;i++) cout << dp[i] << " ";
    cout << "\n";

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