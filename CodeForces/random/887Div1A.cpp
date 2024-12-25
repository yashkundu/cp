/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jul, 2024 | 16:36:53
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n, k;
vector<ll> a;
ll cnt = 0;
ll del = 0;


bool check(ll x) {
    cnt = 0;
    for(int i=n-1;i>=0;i--) {
        if(a[i]>x) continue;
        del = x - a[i] + 1;
        cnt += (del+i)/(i+1);
        x -= (del+i)/(i+1)*(i+1);
    }
    return cnt>k || x>0;
}

 
void solve() {
    cin >> n >> k;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    ll L = 0, R = ll(1e11);
    while(R-L>1) {
        ll mid = (L+R)/2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";

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