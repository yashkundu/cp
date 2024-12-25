/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 20:43:01
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> h;
 
void solve() {
    cin >> n;
    h.resize(n);

    for(int i=0;i<n;i++) cin >> h[i];

    int ans = h[n-1];

    for(int i=n-2;i>=0;i--) {
        ans = max(ans+1, h[i]);
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/