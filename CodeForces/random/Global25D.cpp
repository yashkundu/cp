/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jun, 2024 | 13:04:00
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
 
void solve() {
    cin >> n >> k;
    if(k>n) {
        cout << "NO\n";
        return;
    }
    if(k==n) {
        cout <<"YES\n1\n1\n";
        return;
    }
    if(2*k-1>n) {
        cout << "NO\n";
        return;
    }

    ll x = n - (k-1);
    cout << "YES\n2\n";
    cout << x << " " << "1\n";


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