/**
*   author: lazyhash(yashkundu)
*   created: 21 Apr, 2024 | 20:06:11
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
 
void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        mp[a]++;
    }


    int ans = 0;
    for(auto p: mp) {
        ans += p.second/3;
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