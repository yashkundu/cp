/**
*    author:  lazyhash(yashkundu)
*    created: 12 Jul, 2024 | 12:55:40
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll lim = ll(1e18)+100;


set<ll> st;


void init() {
    ll cur = 0;
    ll f = 1;
    for(int k=2;k<=100;k++) {
        cur = 0LL;
        f = 1LL;
        for(int i=0;i<60;i++) {
            cur += f;
            if(i>1) st.insert(cur);
            if(f>lim/k) break;
            f *= k;
            if(cur+f>lim) break;
        }
    }
}


ll find(ll k, int h) {
    ll cur = 0LL;
    ll f = 1LL;
    for(int i=0;i<h;i++) {
        cur += f;
        if(i<h-1) {
            if(f>lim/k) return lim;
            f *= k;
            if(cur+f>lim) return lim;
        }
    }
    return cur;
}


ll n;

 
void solve() {
    cin >> n;
    if(st.count(n)) {
        cout << "YES\n";
        return;
    }

    for(int h=3;h<10;h++) {
        ll L = 1, R = ll(1e9);
        while(R-L>1) {
            ll mid = (L+R)/2;
            if(find(mid, h)>=n) R = mid;
            else L = mid;
        }
        if(find(R, h)==n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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