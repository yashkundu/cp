/**
*    author:  lazyhash(yashkundu)
*    created: 28 Jan, 2023 | 12:07:31
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll &x: a) {
        cin >> x;
        sum += x;
    }
    ll ans = 1;

    ll cur = 0;
    for(int i=0;i<n-1;i++) {
        cur += a[i]; sum -= a[i];
        ans = max(ans, __gcd(cur, sum));
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/