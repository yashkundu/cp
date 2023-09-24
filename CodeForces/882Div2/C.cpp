/**
*   author: lazyhash(yashkundu)
*   created: 08 Jul, 2023 | 15:50:50
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int M = 256;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<bool> cnt(M, 0);
    cnt[0] = 1;
    int pre = 0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        pre ^= a;
        for(int j=0;j<M;j++) {
            if(cnt[j]) ans = max(ans, pre^j);
        }
        cnt[pre] = 1;
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