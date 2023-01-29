/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jan, 2023 | 00:11:12
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
    vector<int> a(n, 0), b(n, 0);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<pair<int, int>> v;
    for(int i=0;i<n;i++) v.emplace_back(a[i], b[i]);

    sort(v.begin(), v.end());

    // dp[i] - the min element which is the end of a lis of length i
    vector<int> dp;

    for(int i=0;i<n;i++) {
        int x = v[i].second;
        vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), x);
        if(it==dp.end()) dp.push_back(x);
        else *it = x;
    }

    int ans = n;
    ans += dp.size();

    cout << ans << "\n";


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