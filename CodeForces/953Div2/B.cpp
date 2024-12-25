/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jun, 2024 | 14:44:56
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, a, b;
 
void solve() {
    cin >> n >> a >> b;

    ll ans = n*a;
    if(a>=b) {
        cout << ans << "\n";
        return;
    }

    ll del = min(b - a, n);
    ans = b*(b+1)/2 - (b-del)*(b-del+1)/2 + (n-del)*a;
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