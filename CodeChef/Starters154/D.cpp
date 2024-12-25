/**
*    author:  lazyhash(yashkundu)
*    created: 02 Oct, 2024 | 21:46:10
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
vector<ll> a;
vector<pair<ll, ll>> segs;
ll ans = 0;

void solve() {

    cin >> n;
    a.resize(n);
    segs.clear();

    for(int i=0;i<n;i++) cin >> a[i];


    sort(a.begin(), a.end());

    for(int i=1;i<n;i++) {
        segs.push_back({a[i]-a[i-1]+1, a[i]+a[i-1]-1});
    }


    sort(segs.begin(), segs.end());


    ans = 0;

    ll cur = 0;


    for(auto [x, y]: segs) {
        if(cur<x) {
            ans += y-x+1;
            cur = y;
        }  else {
            ans += max(0LL, y-cur);
            cur = max(cur,y);
        }
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