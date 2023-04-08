/**
*    author:  lazyhash(yashkundu)
*    created: 18 Feb, 2023 | 12:47:27
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    ll a, b;
    cin >> a >> b;
    ll n, m;
    cin >> n >> m;

    ll ans = 2e18;

    ans = min(ans, b*n);
    ans = min(ans, a*n - n/(m+1)*a);
    ans = min(ans, n/(m+1)*m*a + (n%(m+1))*b);

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