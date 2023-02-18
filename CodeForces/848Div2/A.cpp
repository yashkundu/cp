/**
*    author:  lazyhash(yashkundu)
*    created: 06 Feb, 2023 | 08:29:34
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    int ans = -1e9;

    vector<int> a(n);

    int sum = 0;
    for(int &x: a) {
        cin >> x;
        sum += x;
    }

    for(int i=0;i<n-1;i++) {
        ans = max(ans, sum - 2*(a[i] + a[i+1]));
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