/**
*   author: lazyhash(yashkundu)
*   created: 15 Oct, 2023 | 20:45:15
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
    if(n<=6 || n==9) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << 1 << " " << (2+(n%3==0?2:0)) << " " << (n-3-((n%3==0)?2:0)) << "\n";

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