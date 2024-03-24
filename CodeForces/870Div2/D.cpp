/**
*   author: lazyhash(yashkundu)
*   created: 14 May, 2023 | 14:20:30
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
    vector<int> b(n), l(n), r(n);
    for(int i=0;i<n;i++) {
        cin >> b[i];
        l[i] = b[i] + i + 1;
        r[i] = b[i] - i - 1;
    }
    for(int i=1;i<n;i++) l[i] = max(l[i-1], l[i]);
    for(int i=n-2;i>=0;i--) r[i] = max(r[i+1], r[i]);
    int ans = 0;

    for(int i=1;i<n-1;i++) ans = max(ans, b[i] + l[i-1] + r[i+1]);
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