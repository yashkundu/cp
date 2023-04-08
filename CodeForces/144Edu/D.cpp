/**
*   author: lazyhash(yashkundu)
*   created: 03 Mar, 2023 | 17:20:29
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


vector<ll> calculate(vector<ll> &v) {
    int n = v.size();
    vector<ll> dp(n+1, 0);
    for(int i=n-1;i>=0;i--) {
        dp[i] = max(0LL, v[i]+dp[i+1]);
    }
    return dp;
}
 
 
void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    if(x>0) {
        vector<ll> newA = a;
        for(int i=0;i<n;i++) newA[i] -= x;

        vector<ll> dp = calculate(newA);
        ll ans = 0;

        for(int i=0;i<n;i++) {
            ll cur_sum = 0;
            for(int j=i;j<min(i+k, n);j++) {
                cur_sum += a[j] + x;
                ans = max(ans, cur_sum);
            }
            ans = max(ans, cur_sum + dp[min(i+k, n)]);
        }

        cout << ans << "\n";

    } else {
        x = abs(x);
        vector<ll> newA = a;
        for(int i=0;i<n;i++) newA[i] += x;
        for(int i=n-1;i+k>=n;i--) newA[i] -= 2*x;
        ll ans = 0;
        for(int i=0;i<=k;i++) {
            vector<ll> dp = calculate(newA);
            for(int i=0;i<n;i++) ans = max(ans, dp[i]);
            if(i<k) newA[i] -= 2*x;
            if(i<k) newA[n-k+i] += 2*x;
        }
        cout << ans << "\n";
    }

    

    


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