/**
*    author:  lazyhash(yashkundu)
*    created: 29 Oct, 2024 | 08:51:26
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<ll> a, sa, fa;

int q;
ll l, r;

ll numterms(int ind) {
    ll tot = 1LL*n*(n+1)/2 - 1LL*(n-ind)*(n-ind+1)/2;
    return tot;
}


ll query(ll ind) {
    int L = 0, R = n;
    while(R-L>1) {
        int mid = (L+R)/2;
        if(numterms(mid)>=ind) R = mid;
        else L = mid;
    }

    int x = R;
    int del = ind - numterms(x-1);


    ll ans = fa[x-1];
    ll extra = (fa[x] - fa[x-1]) - (fa[x+del] - fa[x+del-1]);
    extra -= (sa[x+del-1] - sa[x-1])*(n-x-del+1);
    ans += extra;
    return ans;
}


 
void solve() {
    cin >> n;
    a.resize(n+1);
    sa.resize(n+2);
    fa.resize(n+2);


    a[0] = sa[0] = fa[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sa[i] = a[i];
        fa[i] = a[i]*(n-i+1);
    }

    sa[n+1] = fa[n+1] = 0;

    for(int i=n-1;i>0;i--) fa[i] += fa[i+1];
    for(int i=1;i<=n+1;i++) fa[i] += fa[i-1];
    for(int i=1;i<=n+1;i++) sa[i] += sa[i-1];

    cin >> q;
    
    for(int i=0;i<q;i++) {
        cin >> l >> r;
        ll ans = query(r) - query(l-1);
        cout << ans << "\n";
    }





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