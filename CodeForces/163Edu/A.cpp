/**
*   author: lazyhash(yashkundu)
*   created: 15 Mar, 2024 | 20:07:30
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
    if(n&1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string a = "AA", b = "BB";
    string ans = a;

    int cnt = 2;
    while(cnt<n) {
        if(cnt%4) {
            ans += b;
        } else {
            ans += a;
        }
        cnt += 2;
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