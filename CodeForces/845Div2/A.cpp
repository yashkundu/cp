/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jan, 2023 | 12:42:04
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
    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 0;

    for(int i=0;i<n;) {
        int j = i;
        while(j<n && (a[i]%2==a[j]%2)) j++;
        ans += (j-i-1);
        i = j;
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