/**
*   author: lazyhash(yashkundu)
*   created: 09 Dec, 2023 | 23:28:07
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
    vector<int> v(n);
    for(int &x: v) cin >> x;
    int minEl = 1e9, maxEl = 0;
    for(int x: v) {
        minEl = min(minEl, x);
        maxEl = max(maxEl, x);
    }

    vector<int> ans;
    while(minEl!=maxEl) {
        if(minEl&1) {
            ans.push_back(1);
            minEl = (minEl+1)/2;
            maxEl = (maxEl+1)/2;
        } else {
            ans.push_back(0);
            minEl /= 2;
            maxEl /= 2;
        }
    }

    cout << ans.size() << "\n";
    if(ans.size()<=n) {
        for(int &x: ans) cout << x << " ";
        cout << "\n";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/