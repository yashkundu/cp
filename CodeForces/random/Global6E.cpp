/**
*   author: lazyhash(yashkundu)
*   created: 26 Mar, 2024 | 22:14:23
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
const int N = 2e5+10;
int a[N], award[N];

map<pair<int, int>, int> mp;
 
void solve() {
    int n;
    cin >> n;
    mp.clear();
    fill(award, award+n, 0);

    ll ans = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        ans += a[i];
    }

    int q;
    cin >> q;
    int s, t, u;

    while(q--) {
        cin >> s >> t >> u;
        u--;
        if(mp.find({s, t})!=mp.end()) {
            int p = mp[{s, t}];
            award[p]--;
            if(award[p]<a[p]) ans++;
        }

        if(u<0) mp.erase({s, t});
        else {
            mp[{s, t}] = u;
            award[u]++;
            if(award[u]<=a[u]) ans--;
        }
        cout << ans << "\n";
    }



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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