/**
*   author: lazyhash(yashkundu)
*   created: 30 Sep, 2023 | 20:37:12
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
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = b, del = 0;
    a--;
    for(int i=0;i<n;i++) {
        ll x;
        cin >> x;
        ans += x;
        del += max(0LL, x-a);
    }
    cout << (ans-del) << "\n";

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