/**
*    author:  lazyhash(yashkundu)
*    created: 01 Jan,2023 | 13:06:49
**/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n, 0);
    int x = 1e9+10;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        x = min(x, a[i]);
    }

    x = x*2;
    x--;

    ll ans = 0;

    for(int i=0;i<n;i++) {
        ans += (a[i]+x-1)/x - 1;
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