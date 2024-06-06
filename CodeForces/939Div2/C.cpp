/**
*   author: lazyhash(yashkundu)
*   created: 13 Apr, 2024 | 20:27:33
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
    ll ans = 0;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        if(1LL*n*(n+1)/2>1LL*i*n) v.push_back(i);
        ans += max(1LL*n*(n+1)/2, 1LL*i*n);
    }
    int ops = n + v.size();
    cout << ans << " " << ops << "\n";

    for(int i=1;i<=n;i++) {
        cout << 1 << " " << i << " ";
        for(int j=1;j<=n;j++) cout << j << " ";
        cout << "\n";
    }
    for(int i: v) {
        cout << 2 << " " << i << " ";
        for(int j=1;j<=n;j++) cout << j << " ";
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