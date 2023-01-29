/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jan, 2023 | 12:52:14
**/
#include <iostream>
#include <vector>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const ll mod = 1e9+7;
const int N = 1e5+10;

ll add(ll a, ll b) {
    a += b;
    if(a>=mod) a-=mod;
    return a;
}

ll mul(ll a, ll b) {
    return (a*b)%mod;
}

vector<ll> fact(N, 0);




void precalc() {
    fact[0] = 1;
    for(int i=1;i<N;i++) {
        fact[i] = mul(fact[i-1], i);
    }
}
 
void solve() {
    int n;
    cin >> n;
    ll ans = mul(fact[n], mul(n, n-1));
    cout << ans << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    precalc();
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