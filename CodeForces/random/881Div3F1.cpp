/**
*    author:  lazyhash(yashkundu)
*    created: 13 Jul, 2024 | 09:34:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = int(2e5)+10;

int dp[N][2];
//  0 -mn | 1 - mx
int dp2[N][2];

int n;
int u, v, x, k;
char ch;

 
void solve() {
    cin >> n;
    dp[1][0] = dp2[1][0] = 0;
    dp[1][1] = dp2[1][1] = 1;
    int sz = 1;

    for(int i=1;i<=n;i++) {
        cin >> ch;
        if(ch=='+') {
            sz++;
            cin >> v >> x;
            dp2[sz][0] = min(min(0, x), x+dp2[v][0]);
            dp[sz][0] = min(dp[v][0], dp2[sz][0]);
            dp2[sz][1] = max(max(0, x), x+dp2[v][1]);
            dp[sz][1] = max(dp[v][1], dp2[sz][1]);
        } else {
            cin >> u >> v >> k;
            if(k>=dp[v][0] && k<=dp[v][1]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/