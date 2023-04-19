/**
*   author: lazyhash(yashkundu)
*   created: 08 Apr, 2023 | 20:13:32
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, m;
    cin >> n >> m;
    int x1, x2, x3;
    cout << "? 1 1" << endl;
    cin >> x1;
    if(x1==0) {
        cout << "! 1 1" << endl;
        return;
    }
    cout << "? 1 " << min(1+x1, m) << endl;
    cin >> x2;
    if(x2==0) {
        cout << "! 1 " << min(1+x1, m) << endl;
        return;
    }
    assert(x2<=x1);
    if(x2!=x1) {
        cout << "! " << min(1+x2, n) << " " << min(1+x1, m) << endl;
        return;
    }
    cout << "? " << min(1+x1, n) << " " << "1" << endl;
    cin >> x3;
    assert(x3<=x1);
    cout << "! " << min(1+x1, n) << " " << min(1+x3, m) << endl;
    

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