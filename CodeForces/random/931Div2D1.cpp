/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 14:05:03
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
ll newN; 

void solve() {
    cin >> n >> m;

    int bit1 = 63 - __builtin_clzll(n);
    int bit2 = 63 - __builtin_clzll(m);

    if(bit1==bit2) {
        cout << 1 << "\n";
        cout << n << " " << m << "\n";
        return;
    }

    ll tmp = n^(1LL<<bit1);
    if(tmp==0) {
        cout << "-1\n";
        return;
    }

    int bit3 = 63 - __builtin_clzll(n ^ (1LL<<bit1));
    
    newN = (1LL<<(bit3+1)) - 1;

    if(newN<m) {
        cout << "-1\n";
        return;
    }

    if(newN==m) {
        cout << "1\n";
        cout << n << " " << m << "\n";
        return;
    }

    cout << "2\n";
    cout << n << " " << newN << " " << m << "\n";






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