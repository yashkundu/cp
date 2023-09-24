/**
*   author: lazyhash(yashkundu)
*   created: 27 Aug, 2023 | 00:36:04
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <bitset>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
vector<int> a(2*N, 0);
bitset<N> b;
 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 0;
    ll sum = 0;
    b.set(0, 1);

    for(int i=0;i<2*n;i++) {
        b |= (b<<a[i]);
        sum += a[i];
        if(b[i]==1) {
            b.set(i, 0);
            ans = max(ans, sum - i);
        }
    }

    cout << ans << "\n";

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/