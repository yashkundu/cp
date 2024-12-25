/**
*    author:  lazyhash(yashkundu)
*    created: 29 Sep, 2024 | 21:20:31
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


ll k;



bool check(ll x) {
    ll sq = (ll)sqrtl(x);
    ll num = x - sq;
    return num>=k;
}

 
void solve() {
    cin >> k;

    ll L = 1, R = (ll)2e18;

    while(R-L>1) {
        ll mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";



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