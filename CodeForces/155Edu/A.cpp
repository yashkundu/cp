/**
*   author: lazyhash(yashkundu)
*   created: 24 Sep, 2023 | 20:09:15
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++) {
        int s, e;
        cin >> s >> e;
        v.emplace_back(s, e);
    }
    int w = v[0].first;
    int maxE = 0;
    for(int i=1;i<n;i++) {
        if(v[i].first>=w) {
            maxE = max(maxE, v[i].second);
        }
    }
    if(maxE<v[0].second) cout << v[0].first << "\n";
    else cout << "-1\n";
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