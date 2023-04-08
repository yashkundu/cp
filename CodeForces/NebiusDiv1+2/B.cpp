/**
*   author: lazyhash(yashkundu)
*   created: 17 Mar, 2023 | 00:15:50
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
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> t(n);
    for(int &x: t) cin >> x;


    int ans = 0;

    for(int i=0;i<n;) { 
        ans++;
        int left = k;
        int rpt = t[i] + w + d;
        while(i<n && left-->0 && t[i]<=rpt) i++;
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