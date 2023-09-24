/**
*   author: lazyhash(yashkundu)
*   created: 16 Jul, 2023 | 16:42:29
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
    vector<ll> a(n+1, 0);
    a[0] = 0;
    int ind = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll del = 0;
    ll mn = 1e18;
    for(int i=n;i>=0;i--) {
        if(a[i]-mn>del) {
            ind = i;
            del = a[i]-mn;
        } 
        mn = min(mn, a[i]);
    }
    cout << a[ind] << "\n";
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