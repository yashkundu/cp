/**
*   author: lazyhash(yashkundu)
*   created: 18 Mar, 2024 | 22:16:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N =251;
int c[2*N][2*N];
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<2*n;i++) {
        for(int j=0;j<2*n;j++) {
            cin >> c[i][j];
        }
    }

    ll ans = 0;

    for(int i=n;i<2*n;i++) {
        for(int j=n;j<2*n;j++) ans += c[i][j];
    }

    vector<pair<int, int>> goodPts = {
        {0, n}, {0, 2*n-1}, {n-1, n}, {n-1, 2*n-1},
        {n, 0}, {n, n-1}, {2*n-1, 0}, {2*n-1, n-1}
    };

    int mnCost = 1e9+10;
    for(auto [x, y]: goodPts) {
        mnCost = min(mnCost, c[x][y]);
    }

    ans += mnCost;
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