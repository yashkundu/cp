/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jun, 2024 | 09:42:43
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 

int l, r; 
 
void solve() {
    cin >> l >> r;
    int cnt = 0;
    int f = 1;
    int ans = 0;
    for(int i=0;i<30;i++) {
        f *= 2;
        cnt++;
        if(f>=l && f<=r) ans = cnt;
    }

    cout << ans << "\n";
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