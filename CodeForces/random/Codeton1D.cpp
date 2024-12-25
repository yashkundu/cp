/**
*    author:  lazyhash(yashkundu)
*    created: 15 Sep, 2024 | 22:52:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
ll x;
 
void solve() {
    cin >> n;

    x = 1;
    while(n%2==0) {
        x *= 2;
        n /= 2;
    }

    if(n==1) {
        cout << "-1\n";
        return;
    }

    if(n>=2*x+1) {
        cout << 2*x << "\n";
    } else {
        cout << n << "\n";
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