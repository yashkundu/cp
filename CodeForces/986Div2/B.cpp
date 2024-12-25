/**
*    author:  lazyhash(yashkundu)
*    created: 11 Nov, 2024 | 01:20:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, b, c;
 
void solve() {
    cin >> n >> b >> c;
    
    if(b==0) {
        if(n>c+2) {
            cout << "-1\n";
            return;
        }
        ll ans = n;
        if(c<n) ans--;
        cout << ans << "\n";
        return;
    }

    ll ans = n;

    if(c<n) {
        ans -= (n-c-1)/b+1;
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