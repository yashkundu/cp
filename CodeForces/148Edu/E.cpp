/**
*   author: lazyhash(yashkundu)
*   created: 23 May, 2023 | 07:54:48
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int N = 1e7+10;
vector<ll> a(N);
const int K = 6;
vector<vector<ll>> val(K, vector<ll>(N));
const ll mod=998244353;




ll sum(ll a, ll b) {
    a += b;
    if(a>=mod) a -= mod;
    return a;
}

ll mul(ll a, ll b) {
    return(a*b)%mod;
}

 
void solve() {
    int n, k;
    ll a1, x, y, m;
    cin >> n;
    cin >> a1 >> x >> y >> m;
    cin >> k;


    a[0] = a1;
    for(int i=1;i<n;i++) a[i] = (a[i-1]*x + y)%m;


    val[0][0] = a[0];
    for(int i=1;i<n;i++) val[0][i] = sum(a[i], val[0][i-1]);


    auto c = [](int n, int r) {
        if(n<r) return 0;
        else return 1;
    };

    for(int j=1;j<=k;j++) {
        // 
        val[j][0] = mul(c(1, j), a[0]);
        for(int i=1;i<n;i++) {  
            val[j][i] = sum(sum(val[j][i-1], val[j-1][i-1]), mul(c(1, j), a[i]));
        }
    }

    ll ans = 0;
    for(int i=0;i<n;i++) ans ^= (val[k][i]*(i+1));
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