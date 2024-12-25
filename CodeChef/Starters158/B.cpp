/**
*    author:  lazyhash(yashkundu)
*    created: 30 Oct, 2024 | 20:09:21
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

int n;
vector<ll> a, b, v;
 
void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);


    ll ans = (ll)1e18+10;
    ll sa = 0, sb = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        sa += a[i];
    }

    for(int i=0;i<n;i++) {
        cin >> b[i];
        sb += b[i];
    }

    if(n==1) {
        cout << sb << '\n';
        return;
    }

    ans = min(sa, sb);


    v.clear();
    for(int i=0;i<n;i++) v.push_back(a[i]-b[i]);

    sort(v.rbegin(), v.rend());

    ll cur = 0;

    for(int i=0;i<n-2;i++) {
        cur += v[i];
        ans = min(ans, sa-cur);
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