/**
*   author: lazyhash(yashkundu)
*   created: 04 Mar, 2023 | 12:29:16
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if(min(a, d) && !max(b, c)) {
        cout << "No\n";
    }
    else if(abs(b-c)<=1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/