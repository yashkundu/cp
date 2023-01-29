/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jan, 2023 | 20:31:33
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n+1, 0);

    ll maxP = 0, maxN = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
        if(a[i]>0) maxP = max(maxP, a[i]);
        else if(a[i]<0) maxN = max(maxN, -a[i]);
    }

    cout << (maxP+maxN) << "\n";



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