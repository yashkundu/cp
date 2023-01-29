/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jan, 2023 | 12:59:45
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


void solve() {
    ll n, x;
    cin >> n >> x;

    if((n&x)!=x) {
        cout << "-1\n";
        return;
    }

    int msb = 60;
    while(msb>=0 && ((n>>msb)&1)==((x>>msb)&1)) msb--;
    if(msb<0) {
        cout << n << "\n";
        return;
    }
    if((n>>(msb+1))&1) {
        cout << "-1\n";
        return;
    }
    int lsb = 0;
    while(lsb<=63 && !((x>>lsb)&1)) lsb++;

    if(msb>lsb) {
        cout << "-1\n";
        return;
    }

    cout << ((n&((-1LL)<<(msb+1)))|(1LL<<(msb+1))) << "\n";


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