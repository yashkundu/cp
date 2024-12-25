/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jul, 2024 | 13:06:06
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int MAXN = 5005;

int n, p;

ll add(ll x, ll y) {
    x += y;
    if(x>=p) x -= p;
    return x;
}

ll mul(ll x, ll y) {
    return (x*y)%p;
}

ll pow(ll a, int n) {
    ll res = 1;
    while(n) {
        if(n&1) res = mul(res, a);
        a = mul(a, a);
        n = n>>1;
    }
    return res;
}

ll inv(ll x) {
    return pow(x, p-2);
}



ll fact[MAXN], invFact[MAXN];

void init() {
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) fact[i] = mul(fact[i-1], i%p);

    invFact[MAXN-1] = inv(fact[MAXN-1]);
    for(int i=MAXN-2;i>=0;i--) invFact[i] = mul(invFact[i+1], (i+1)%p);
}

ll C(int n, int r) {
    if(n<r) return 0;
    return mul(fact[n], mul(invFact[n-r], invFact[r]));
}

ll ans = 0;

 
void solve() {
    cin >> n >> p;
    init();


    int ini = (n%2==0);
    ans = 0;
    for(int i=1;i<=(n+1)/2;i++) {
        int m = max(0, i - 2);
        int tot = n-2 - (i!=1);
        for(int j=0;j<=m;j++) {
            ans += mul(ini, mul(C(m, j), fact[tot-j]));
        }
        ini++;
    }

    ans = mul(ans, n);

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