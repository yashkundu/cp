/**
*    author:  lazyhash(yashkundu)
*    created: 09 Nov, 2024 | 20:08:21
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll l, r, k;
 
void solve() {
    cin >> l >> r >> k;

    
    if(k==1) {
        cout << (r-l+1) << "\n";
        return; 
    }

    ll x = r/k;

    ll num = max(0LL, x-l+1);
    cout << num << "\n";








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