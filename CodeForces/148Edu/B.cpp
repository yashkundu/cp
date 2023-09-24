/**
*   author: lazyhash(yashkundu)
*   created: 20 May, 2023 | 15:20:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;

    sort(a.rbegin(), a.rend());
    for(int i=1;i<n;i++) a[i] += a[i-1];


    ll ans = 0;

    for(int i=0;i<=k;i++) {
        int j = k-i;
        ans = max(ans, a[n-1-2*j]-(i>0?a[i-1]:0));
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/