/**
*    author:  lazyhash(yashkundu)
*    created: 15 Aug, 2024 | 20:23:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll k;
vector<ll> a;
 
void solve() {
    cin >> n >> k;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.rbegin(), a.rend());



    for(int i=1;i<n;i+=2) {
        ll del = min(k, a[i-1]-a[i]);
        k -= del;
        a[i] += del;
    }

    ll ans = 0;
    for(int i=1;i<n;i+=2) ans += a[i-1] - a[i];


    if(n&1) {
        ans += a[n-1];
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