/**
*   author: lazyhash(yashkundu)
*   created: 20 Mar, 2023 | 00:41:03
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if(d<b) {
        cout << "-1\n";
        return;
    }
    ans += d-b;
    a += d-b;
    if(a<c) {
        cout << "-1\n";
        return;
    }
    ans += a-c;
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