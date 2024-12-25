/**
*    author:  lazyhash(yashkundu)
*    created: 27 Oct, 2024 | 20:07:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, r, c;
 
void solve() {
    cin >> n >> m >> r >> c;

    ll ans = 0;
    ans += m-c;
    ans += 1LL*(n-r)*(m-1);
    ans += 1LL*(n-r)*m;

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