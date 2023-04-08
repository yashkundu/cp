/**
*    author:  lazyhash(yashkundu)
*    created: 18 Feb, 2023 | 17:09:15
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);

    vector<int> posP(n+1), posQ(n+1); 

    int l1, r1, l2, r2 = 0;


    for(int i=0;i<n;i++) {
        cin >> p[i];
        if(p[i]==1) l1 = r1 = i;
        posP[p[i]] = i;
    }

    for(int i=0;i<n;i++) {
        cin >> q[i];
        if(q[i]==1) l2 = r2 = i;
        posQ[q[i]] = i;
    }

    int mn = min(l1, l2), mx = max(l1, l2);

    ll ans = 1LL*n*(n+1)/2 - 1LL*(mn+1)*(n-mx) - 1LL*(mn+1)*(mx-mn) - 1LL*(n-mx)*(mx-mn) + 1;

    for(int i=1;i<n;i++) {
        int ind1 = posP[i], ind2 = posQ[i];
        if(ind1<l1) l1 = ind1;
        if(ind1>r1) r1 = ind1;
        if(ind2<l2) l2 = ind2;
        if(ind2>r2) r2 = ind2;
        int l = min(l1, l2), r = max(r1, r2);
        int x = -1, y = n;
        if(posP[i+1]<=r) x = max(x, posP[i+1]);
        if(posQ[i+1]<=r) x = max(x, posQ[i+1]);
        if(posP[i+1]>=l) y = min(y, posP[i+1]);
        if(posQ[i+1]>=l) y = min(y, posQ[i+1]);
        ans += 1LL*max(0, l-x)*max(0, y-r);
    }

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/