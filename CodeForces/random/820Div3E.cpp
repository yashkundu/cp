/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jul, 2024 | 20:54:01
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

ll query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    ll x;
    cin >> x;
    return x;
}

void output(ll x) {
    cout <<"! " << x << endl;
}

void solve() {
    for(int i=2;i<100;i++) {
        ll x = query(1, i);
        ll y = query(i, 1);
        if(x==-1) {
            output(i-1);
            return;
        }
        if(x!=y) {
            output(x+y);
            return;
        }
    }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/