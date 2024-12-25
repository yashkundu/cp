/**
*    author:  lazyhash(yashkundu)
*    created: 10 Oct, 2024 | 20:04:46
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
 

int q;
vector<pair<int, pair<int, int>>> v;
vector<int> ans;

map<int, int> mp;

void solve() {
    
    cin >> q;

    for(int i=0;i<q;i++) {
        int t;
        cin >> t;
        int x = 0, y = 0;
        if(t==1) cin >> x;
        else cin >> x >> y;
        v.push_back({t, {x, y}});
    }

    for(int i=q-1;i>=0;i--) {
        if(v[i].first==2) {
            int x = v[i].second.first, y = v[i].second.second;
            if(mp[y]) mp[x] = mp[y];
            else mp[x] = y;
        } else {
            int x = v[i].second.first;
            if(mp[x]) ans.push_back(mp[x]);
            else ans.push_back(x);
        }
    }

    for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
    cout << "\n";


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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/