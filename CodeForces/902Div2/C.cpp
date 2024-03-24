/**
*   author: lazyhash(yashkundu)
*   created: 08 Oct, 2023 | 21:30:04
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
    int n, m, k;
    cin >> n >> m >> k;
    if(k>3) {
        cout << "0\n";
        return;
    }
    if(k==1) {
        cout << "1\n";
    } else if(k==2) {
        int ans = min(m, n-1) + (m/n);
        cout << ans << "\n";
    } else {
        int ans = max(0, m-n+1) - m/n;
        cout << ans << "\n";
    }
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