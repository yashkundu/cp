/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jul, 2024 | 17:30:58
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
    int r, g, b;
    cin >> r >> g >> b;
    string s;
    cin >> s;
    if(s=="Red") cout << min(g, b);
    else if(s=="Green") cout << min(r, b);
    else cout << min(r, g);
    cout << "\n";
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