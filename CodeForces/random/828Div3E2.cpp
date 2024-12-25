/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jul, 2024 | 14:16:46
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll LIM = ll(1e9)+1;

ll a, b, c, d;
ll ab;
ll f;
ll y;


vector<ll> factors(ll x) {
    vector<ll> v;
    for(ll i=1;i*i<=x;i++) {
        if(x%i==0) {
            v.push_back(i);
            if(x/i!=i) v.push_back(x/i);
        }
    }
    return v;
}

 
void solve() {
    cin >> a >> b >> c >> d;

    vector<ll> v1 = factors(a);
    vector<ll> v2 = factors(b);

    ab = a*b;

    vector<ll> v;
    for(ll x: v1) {
        for(ll y: v2) {
            f = x*y;
            if(f<LIM && ab/f<LIM) v.push_back(f);
        }
    }


    for(ll x: v) {
        y = ab/x;
        x = (a/x+1)*x;
        y = (b/y+1)*y;
        if(x<=c && y<=d) {
            cout << x << " " << y << "\n";
            return;
        }
    }

    cout << "-1 -1\n";

    


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