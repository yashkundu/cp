/**
*   author: lazyhash(yashkundu)
*   created: 08 Dec, 2023 | 23:52:16
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

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x: v) cin >> x;
    ll ans = v[0]-1;
    for(int i=1;i<n;i++) ans += max(0, v[i]-v[i-1]);
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