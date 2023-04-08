/**
*    author:  lazyhash(yashkundu)
*    created: 18 Feb, 2023 | 13:13:27
**/
#include <iostream>
#include <vector>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int x, y;
    cin >> x >> y;
    vector<int> ans;
    int mn = min(x, y);
    int mx = max(x, y);
    assert(x>y);
    ans.push_back(mn);
    for(int i=1;i<=mx-mn;i++) ans.push_back(mn+i);
    for(int i=1;i<mx-mn;i++) ans.push_back(mx-i);

    cout << ans.size() << "\n";
    for(int &x: ans) cout << x << " ";
    cout << "\n";

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