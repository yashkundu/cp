/**
*    author:  lazyhash(yashkundu)
*    created: 06 Feb, 2023 | 08:56:46
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> p(n), a(m), pos(n);
    
    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    for(int i=0;i<m;i++) {
        cin >> a[i];
        a[i]--;
    }

    int ans = 1e9;

    for(int i=0;i<m-1;i++) {
        int cur = max(0, pos[a[i+1]] - pos[a[i]]);
        if(pos[a[i]] + d - pos[a[i+1]] + 1 <= (n-1) - pos[a[i+1]] + pos[a[i]]) {
            cur = min(cur, max(0, pos[a[i]] + d - pos[a[i+1]] + 1));
        }
        ans = min(ans, cur);
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