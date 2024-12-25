/**
*    author:  lazyhash(yashkundu)
*    created: 28 Oct, 2024 | 20:14:50
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int x, y, k;
 
void solve() {
    cin >> x >> y >> k;
    int d = min(x, y);


    cout << "0 0 " << d << " " << d << "\n";
    cout << 0 << " " << d << " " << d << " " << "0\n";

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