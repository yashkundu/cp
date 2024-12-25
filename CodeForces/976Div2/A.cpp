/**
*    author:  lazyhash(yashkundu)
*    created: 29 Sep, 2024 | 21:05:56
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
 
void solve() {
    cin >> n >> k;

    if(k==1) {
        cout << n << "\n";
        return;
    }


    ll ans = 0;


    while(n) {
        ans += n%k;
        n /= k;
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