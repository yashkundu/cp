/**
*    author:  lazyhash(yashkundu)
*    created: 08 Sep, 2024 | 21:52:59
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<ll> h;
vector<ll> vec1, vec2;
ll mx;


bool check(ll x, vector<ll> &y) {
    ll evens = x/2;
    ll odds = x - evens;
    for(int i=0;i<n;i++) {
        ll x = y[i];
        ll delta = min(evens, x/2);
        evens -= delta;
        x -= 2*delta;
        odds -= x;
    }
    return odds>=0;
}

 
void solve() {
    cin >> n;
    h.resize(n);
    vec1.resize(n);
    vec2.resize(n);

    mx = 0;

    for(int i=0;i<n;i++) {
        cin >> h[i];
        mx = max(mx, h[i]);
    }

    for(int i=0;i<n;i++) {
        vec1[i] = mx - h[i];
        vec2[i] = mx + 1 - h[i];
    }


    ll L = -1, R = (ll)1e15;

    while(R-L>1) {
        ll mid = (L+R)/2;
        if(check(mid, vec1) || check(mid, vec2)) R = mid;
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