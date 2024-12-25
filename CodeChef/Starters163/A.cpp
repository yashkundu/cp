/**
*    author:  lazyhash(yashkundu)
*    created: 04 Dec, 2024 | 20:02:25
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll k;
vector<ll> a;
 
void solve() {
    cin >> n >> k;
    a.resize(n);

    ll sum = 0;
    int cnt = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(ceil((long double)a[i]/k)!=floor((long double)a[i]/k)) cnt++;
        sum += (ll)floor((long double)a[i]/k);
    }

    if(sum<=0 && sum+cnt>=0) cout << "YES\n";
    else cout << "NO\n";

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