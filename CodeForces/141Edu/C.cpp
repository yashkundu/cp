/**
*    author:  lazyhash(yashkundu)
*    created: 02 Feb, 2023 | 21:21:01
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    int sum=0;
    vector<pair<int, int>> a(n+1);
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        a[i].first = x;
        a[i].second = i;
        sum += x;
    }
    if(sum<=m) {
        cout << "1\n";
        return;
    }

    sort(a.begin()+1, a.end());
    for(int i=1;i<=n;i++) a[i].first += a[i-1].first;
    for(int i=1;i<=n;i++) pos[a[i].second] = i;

    int ans = n+1;
    for(int w=1;w<n;w++) {
        if(a[w].first>m) break;
        ans = min(ans, n-w+1);
        if(pos[w+1]<=w) ans = min(ans, n-w);
        else {
            int left = m - (a[pos[w+1]].first - a[pos[w+1]-1].first);
            if(left<0) continue;
            int ind = upper_bound(a.begin()+1, a.end(), make_pair(left+1, 0)) - a.begin() - 1;
            if(ind>=w-1) ans = min(ans, n-w);
        }
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