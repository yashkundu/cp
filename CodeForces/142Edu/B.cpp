/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jan, 2023 | 21:04:47
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    ll a[4];
    for(int i=0;i<4;i++) cin >> a[i];
    if(!a[0]) {
        cout << "1\n";
        return;
    }
    ll ans = a[0] + 2*min(a[1], a[2]) + min(a[0], abs(a[1]-a[2]) + a[3]);
    if(ans != a[0]+a[1]+a[2]+a[3]) ans++;
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