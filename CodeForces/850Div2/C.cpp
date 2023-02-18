/**
*    author:  lazyhash(yashkundu)
*    created: 12 Feb, 2023 | 16:17:00
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    ll ans = 0;
    int wanted = 1;

    sort(a.begin(), a.end());
    for(int i=0;i<n;i++) {
        if(a[i]==wanted) {
            wanted++; continue;
        }
        if(a[i]<wanted) continue;
        ans += a[i]-wanted;
        wanted++;
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