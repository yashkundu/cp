/**
*   author: lazyhash(yashkundu)
*   created: 27 Aug, 2023 | 21:05:20
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
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    if(k*ak>=m) {
        ll leftOnes = max(m%k-a1, 0LL);
        cout << leftOnes << "\n";
        return;
    }
    ll remaining = m - k*ak;
    if(a1>=remaining) {
        cout << "0\n";
        return;
    }
    remaining -= a1;
    if((k - remaining%k)%k <= a1) remaining += (k - remaining%k)%k;
    ll ans = remaining/k + remaining%k;
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