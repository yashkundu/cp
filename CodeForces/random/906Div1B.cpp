/**
*    author:  lazyhash(yashkundu)
*    created: 04 Jul, 2024 | 19:51:31
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
ll c;
vector<ll> a;
vector<ll> pref;
 
void solve() {
    cin >> n >> c;
    a.resize(n+1);
    pref.resize(n+1);

    for(int i=1;i<=n;i++) cin >> a[i];

    pref[0] = 0;
    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + a[i];


    int last = 1;
    for(int i=2;i<=n;i++) {
        if(pref[last]+a[i]>=i*c) {
            last = i;
        }
    }

    if(last==n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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