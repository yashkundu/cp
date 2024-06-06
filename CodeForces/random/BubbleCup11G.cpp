/**
*   author: lazyhash(yashkundu)
*   created: 15 May, 2024 | 20:26:31
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set __gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type,less<pair<int, int>>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> 


map<int, ordered_set> mp;

const int N = 1e5+10;


vector<pair<int, pair<int, int>>> robots;

int n, k;

void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int x, r, q;
        cin >> x >> r >> q;
        robots.push_back({r, {x, q}});
    }

    sort(robots.rbegin(), robots.rend());


    ll ans = 0;

    int cntr = 1;
    for(auto p: robots) {
        int r = p.first, x = p.second.first, q = p.second.second;

        for(int newQ=q-k; newQ<=q+k;newQ++) {
            if(mp.find(newQ)==mp.end()) continue;
            ans += mp[newQ].order_of_key({x+r+1, 0}) - mp[newQ].order_of_key({x-r, 0});
        }

        if(mp.find(q)==mp.end()) mp[q] = ordered_set();
        mp[q].insert({x, cntr++});
    }

    cout << ans << "\n";


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