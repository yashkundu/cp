/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jul, 2024 | 14:01:26
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using oset = tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>;

const int MAXN = int(2e5)+10;
const int inf = int(1e9)+100;

int l[MAXN], r[MAXN], c[MAXN];
vector<int> cols[MAXN];
int ans[MAXN];
int n;

oset sl, sr;
 
void solve() {
    cin >> n;
    sl.clear(), sr.clear();

    for(int i=0;i<n;i++) cols[i].clear();

    for(int i=0;i<n;i++) {
        cin >> l[i] >> r[i] >> c[i], c[i]--;
        cols[c[i]].push_back(i);
        sl.insert({l[i], i});
        sr.insert({r[i], i});
    }

    fill(ans, ans+n, inf);


    for(int c=0;c<n;c++) {
        for(auto ind: cols[c]) {
            sl.erase({l[ind], ind});
            sr.erase({r[ind], ind});
        }
        for(auto ind: cols[c]) {
            if((int)sr.order_of_key({l[ind], 0}) + ((int)sl.size() - (int)sl.order_of_key({r[ind], inf})) < n - (int)cols[c].size()) {
                ans[ind] = 0;
                continue;
            }
            auto it = sr.lower_bound({l[ind], 0});
            if(it!=sr.begin()) ans[ind] = min(ans[ind], l[ind]-prev(it)->first);
            auto it2 = sl.lower_bound({r[ind]+1, 0});
            if(it2!=sl.end()) ans[ind] = min(ans[ind], it2->first-r[ind]);
        }

        for(auto ind: cols[c]) {
            sl.insert({l[ind], ind});
            sr.insert({r[ind], ind});
        }
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";





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