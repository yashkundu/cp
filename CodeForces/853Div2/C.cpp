/**
*   author: lazyhash(yashkundu)
*   created: 25 Feb, 2023 | 20:38:38
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<pair<int, int>> v;

    vector<vector<int>> pos(n, vector<int>());

    vector<int> freq(n+m+1, 0);


    for(int i=1;i<=m;i++) {
        int ind, val;
        cin >> ind >> val;
        ind--;
        v.push_back({ind, val});
        pos[ind].push_back(i);
    }

    for(auto &x: pos) reverse(x.begin(), x.end());

    for(int i=0;i<n;i++) {
        int l = 0;
        int val = a[i];
        while(!pos[i].empty()) {
            freq[val] += pos[i].back() - l;
            l = pos[i].back();
            val = v[l-1].second;
            pos[i].pop_back();
        }
        freq[val] += m+1-l;
    }


    ll ans = 2LL*n*m*(m+1)/2;

    for(int i=1;i<=n+m;i++) {
        ans -= 1LL*freq[i]*(freq[i]-1)/2;
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