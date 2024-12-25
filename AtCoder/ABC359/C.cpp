/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 17:44:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll sx, sy, tx, ty;
 
void solve() {
    cin >> sx >> sy >> tx >> ty;

    ll dely = abs(sy-ty);
    ll ans = dely;

    if(sx==tx) {
        cout << ans << "\n";
        return;
    }
    if(sx>tx) {
        ll delx = dely + ((sx+sy)%2==1);
        sx -= delx;
        if(sx<=tx) {
            cout << ans << "\n";
            return;
        }
        ans += (sx-tx+1)/2;
        cout << ans << "\n";
    } else {
        ll delx = dely + ((sx+sy)%2==0);
        sx += delx;
        if(sx>=tx) {
            cout << ans << "\n";
            return;
        }
        ans += (tx-sx+1)/2;
        cout << ans << "\n";
    }


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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