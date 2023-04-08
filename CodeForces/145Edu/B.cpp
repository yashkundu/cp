/**
*   author: lazyhash(yashkundu)
*   created: 23 Mar, 2023 | 20:17:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    ll n;
    cin >> n;

    ll ans = 1e18;

    ll L = 1, R = 1e9;
    while(L<R) {
        ll mid = L + (R-L)/2;
        ll sum = 4*mid*(mid-1);
        if(sum+1>=n) R = mid;
        else L = mid + 1;
    }

    ans = min(ans, (L-1)*2);

    L = 1; R = 1e9;
    while(L<R) {
        ll mid = L + (R-L)/2;
        ll sum = 4*mid*mid;
        if(sum>=n) R = mid;
        else L = mid + 1;
    }

    ans = min(ans, 1 + (L-1)*2);

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