/**
*    author:  lazyhash(yashkundu)
*    created: 04 Sep, 2024 | 22:03:56
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n, q;
vector<ll> a;
vector<ll> psum;

int l, r;
ll k;

 
void solve() {
    cin >> n >> q;
    a.resize(n);
    psum.resize(n+1);
    for(int i=0;i<n;i++) cin >> a[i];
    
    psum[0] = 0;
    for(int i=0;i<n-1;i++) psum[i+1] = abs(a[i] - a[i+1]);


    for(int i=1;i<n;i++) psum[i] += psum[i-1];



    while(q--) {
        cin >> l >> r >> k;
        l--, r--;
        ll orig = abs(a[l] - a[r]);
        ll tot = psum[r] - psum[l];

        if(tot<=k) {
            cout << "0\n";
            continue;
        }


        ll del = min(tot-orig, tot-k);

        ll ans = (del+1)/2;
        tot -= del;
        ans += (tot-k);

        cout << ans << "\n";
    }




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