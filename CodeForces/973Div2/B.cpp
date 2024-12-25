/**
*    author:  lazyhash(yashkundu)
*    created: 20 Sep, 2024 | 20:21:36
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
vector<ll> a;

void solve() {
    cin >> n;
    a.resize(n);

    ll ans = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }


    ans = a[n-1] - a[n-2];
    for(int i=0;i<n-2;i++) ans += a[i];

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