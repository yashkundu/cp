/**
*   author: lazyhash(yashkundu)
*   created: 10 Dec, 2023 | 11:53:35
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int isPairGood(int x, int y) {
    if((x&1)==(y&1)) return 1;
    return 0;
}
 
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << isPairGood(b, c) << " " << isPairGood(a, c) << " " << isPairGood(a, b) << "\n";

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