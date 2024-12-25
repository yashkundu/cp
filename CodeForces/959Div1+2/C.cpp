/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jul, 2024 | 20:31:32
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;


ll a[MAXN];
ll psum[MAXN];

ll ans[MAXN];

ll res = 0;

int n;
ll x;

 
void solve() {
    cin >> n >> x;
    
    psum[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    ans[n+1] = 0LL;
    ans[n+2] = 0LL;

    for(int i=n;i>0;i--) {
        int ind = upper_bound(psum, psum+n+1, psum[i-1] + x) - psum;
        ans[i] = (ind-i) + ans[ind+1];
    }



    res = 0;
    for(int i=1;i<=n;i++) res += ans[i];

    cout << res << "\n";



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