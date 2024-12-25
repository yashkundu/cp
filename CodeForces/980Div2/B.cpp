/**
*    author:  lazyhash(yashkundu)
*    created: 20 Oct, 2024 | 14:50:30
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll a, k;
map<ll, int> mp;
 
void solve() {
    
    cin >> n >> k;
    mp.clear();

    for(int i=0;i<n;i++) {
        cin >> a;
        mp[a]++;
    }

    ll lastel = 0;
    int lastcnt = 0;

    ll num = 0;
    
    for(auto p: mp) {
        if(k==0) break;
        ll cur = (p.first - lastel)*n;
        num += min(k, cur) + lastcnt;
        k -= min(k, cur);
        lastcnt = p.second;
        lastel = p.first;
        n -= p.second;
    }

    cout << num << "\n";




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