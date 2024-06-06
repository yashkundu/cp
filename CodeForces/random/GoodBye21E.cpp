/**
*   author: lazyhash(yashkundu)
*   created: 21 Apr, 2024 | 16:23:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+10;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set __gnu_pbds::tree<int, __gnu_pbds::null_type,less<int>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> 


vector<int> pos[26];
const ll inf = 1e18;
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<26;i++) pos[i].clear();

    string s, t;
    cin >> s >> t;

    for(int i=n-1;i>=0;i--) {
        pos[s[i]-'a'].push_back(i);
    }

    ll ans = inf;
    ll curOps = 0;

    ordered_set st;

    for(int i=0;i<n;i++) {
        for(int j=0;j<t[i]-'a';j++) {
            if(pos[j].empty()) continue;
            int p = pos[j].back();
            ans = min(ans, curOps + (ll)p - (ll)st.order_of_key(p));
        }
        // match the a[1..i] to b[1..i]
        if(pos[t[i]-'a'].empty()) break;
        int p = pos[t[i]-'a'].back();
        pos[t[i]-'a'].pop_back();
        curOps += (p - st.order_of_key(p));
        st.insert(p);
    }

    if(ans==inf) {
        cout << "-1\n";
        return;
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