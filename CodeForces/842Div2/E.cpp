/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jan, 2023 | 15:05:53
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 3e6+10;
vector<ll> fact(N, 0), invFact(N, 0);

ll mod;

ll add(ll a, ll b) {
    a += b;
    if(a>=mod) a -= mod;
    return a;
}

ll sub(ll a, ll b) {
    a -= b;
    if(a<0) a += mod;
    return a;
}

ll mul(ll a, ll b) {
    return (a*b)%mod;
}

ll bExp(ll a, ll n) {
    ll res = 1;
    while(n) {
        if(n&1) res = mul(res, a);
        a = mul(a, a);
        n = n>>1;
    }
    return res;
}

ll pow(ll x, ll n) {
    ll res = 1;
    for(int i=0;i<n;i++) res = mul(res, x);
    return res;
}


void precalc() {
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = mul(fact[i-1], i);
    invFact[N-1] = bExp(fact[N-1], mod-2);
    for(int i=N-2;i>=0;i--) invFact[i] = mul(invFact[i+1], i+1);
}

ll nCr(ll n, ll r) {
    if(n<r) return 0;
    return mul(fact[n], mul(invFact[n-r], invFact[r]));
}
 
 
void solve() {
    int n;
    cin >> n;
    cin >> mod;

    precalc();

    vector<ll> a(4, 0);

    // 1 1 1 2 2 2 3 3 3
    a[0] = 1;

    // 111..... | .....333
    a[1] = sub(mul(2, fact[2*n]), fact[n]);

    // all 1s in first 2n places or mirror
    a[2] = mul(2, mul(mul(nCr(2*n, n), fact[n]), fact[2*n]));

    // all 1s are in first 2n places & all 3's are in last 2*n places
    ll extra = 0;
    // no. of places 1 occupy in first n positions
    for(int i=0;i<=n;i++) {
        // (n-i) places in the second n positions
        // divide all 1s in groups of i, (n-i)
        extra = add(extra, mul(pow(nCr(n, i), 3), mul(fact[n-i], fact[n+i])));
    }
    extra = mul(extra, fact[n]);

    a[2] = sub(a[2], extra);
    a[3] = fact[3*n];

    for(int i=3;i>0;i--) a[i] = sub(a[i], a[i-1]);

    ll ans = 0;
    for(int i=0;i<4;i++) ans = add(ans, mul(i, a[i]));

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