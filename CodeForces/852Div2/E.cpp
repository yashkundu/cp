/**
*    author:  lazyhash(yashkundu)
*    created: 19 Feb, 2023 | 16:34:48
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int inf = 1e9;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> ans(n+1, 0);
    vector<int> dp(n+1, -inf);
    dp[0] = 0;
    
    for(int i=1;i<=n;i++) {
        if(a[i-1]<=i) {
            dp[i] = dp[i-a[i-1]] + 1;
            ans[dp[i] + n - i] = max(ans[dp[i]+n-i], i);
        } else {
            ans[n-a[i-1]+1] = max(ans[n-a[i-1]+1], i);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }

    for(int i=n-1;i>0;i--) ans[i] = max(ans[i], ans[i+1]);

    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        cout << ans[k] << "\n";
    }

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