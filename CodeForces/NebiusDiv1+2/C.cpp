/**
*   author: lazyhash(yashkundu)
*   created: 17 Mar, 2023 | 21:02:47
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
    int n, x, p;
    cin >> n >> x >> p;
    x = (n-x)%n;
    for(int i=1;i<=min(2*n, p);i++) {
        if(int(1LL*i*(i+1)/2%n)==x) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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