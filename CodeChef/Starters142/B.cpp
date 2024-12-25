/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jul, 2024 | 20:37:17
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


bool isPrime(ll x) {
    for(int i=2;1LL*i*i<=x;i++) if(x%i==0) return false;
    return true;
}

ll x;
 
void solve() {
    cin >> x;
    x = max(2LL, x);

    ll p1 = 0, p2 = 0;

    for(ll i=x;i<ll(1e15);i++) {
        if(isPrime(i)) {
            if(p1==0) p1 = i;
            else if(p2==0) p2 = i;
            else {
                cout << p1*p2 << "\n";
                return;
            }
        }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/