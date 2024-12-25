/**
*    author:  lazyhash(yashkundu)
*    created: 07 Jul, 2024 | 14:48:18
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;


int ask(int ind) {
    cout << "? " << ind << endl;
    int x;
    cin >> x;
    return x;
}
 
void solve() {
    cin >> n >> k;
    int res = 0;
    int i;
    for(i=1;i+k-1<=n;i+=k) res ^= ask(i);
    for(;i<=n;i++) res ^= ask(i-k+1);
    cout << "! " << res << endl;
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