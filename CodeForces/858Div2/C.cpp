/**
*   author: lazyhash(yashkundu)
*   created: 20 Mar, 2023 | 10:45:06
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

void solve() {
    int n;
    cin >> n;
    vector<ll> p(2*n, 0);

    for(int i=0;i<2*n;i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    if(n==1) {
        cout << abs(p[0]-p[1]) << "\n";
        return;
    }

    vector<vector<ll>> v;
    if(n==2) {
        v.push_back({2,2,2,2});
        v.push_back({0,0,0,0});
        v.push_back({-1, -1, -1, 2});
    }
    else {
        vector<ll> zeros;
        for(int i=0;i<2*n;i++) zeros.push_back(0);
        v.push_back(zeros);
        if(!(n&1)) {
            vector<ll> misc;
            for(int i=0;i<2*n-1;i++) misc.push_back(-1);
            misc.push_back(n);
            v.push_back(misc);
        }
    }
    

    auto calc_dif = [](vector<ll> &p, vector<ll> &q) {
        int n = p.size();
        ll d = 0;
        for(int i=0;i<n;i++) {
            d += abs(p[i]-q[i]);
        }
        return d;
    };

    ll ans = 1e18;

    for(vector<ll> &x: v) {
        ans = min(ans, calc_dif(p, x));
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/