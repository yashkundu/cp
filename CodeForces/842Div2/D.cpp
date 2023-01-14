/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jan, 2023 | 12:41:28
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


bool checkConsecutive(vector<int> v) {
    for(int i=0;i<v.size()-1;i++) 
        if(v[i]==v[i+1]-1) return true;
    return false;
}
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1, 0);

    for(int i=1;i<=n;i++) cin >> p[i];
    vector<bool> vis(n+1, false);

    vector<vector<int>> v;

    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        int j = i;
        vector<int> cycle;
        while(!vis[j]) {
            vis[j] = true;
            cycle.push_back(j);
            j = p[j];
        }
        v.push_back(cycle);
    }

    int ans = 0;
    bool consecutivePresent = false;
    for(vector<int> cycle: v) {
        ans += cycle.size() - 1;
        sort(cycle.begin(), cycle.end());
        consecutivePresent |= checkConsecutive(cycle);
    }

    if(consecutivePresent) ans -= 1;
    else ans += 1;

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/