/**
*   author: lazyhash(yashkundu)
*   created: 21 Feb, 2023 | 22:45:14
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll &x: a) cin >> x;
    for(ll &x: b) cin >> x;

    vector<ll> pre(n+1, 0);
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + b[i-1];

    vector<ll> ans(n+1, 0), residue(n+1, 0);

    for(int i=0;i<n;i++) {
        int len = lower_bound(pre.begin()+i+1, pre.end(), a[i]+pre[i]) - pre.begin() - i;
        int l = i, r = i+len-1;
        ans[l]++, ans[r]--;
        residue[i+len-1] += a[i] + pre[i] - pre[i+len-1];
    }

    for(int i=1;i<n;i++) ans[i] += ans[i-1];

    for(int i=0;i<n;i++) 
        cout << (ans[i]*b[i]+residue[i]) << " ";
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