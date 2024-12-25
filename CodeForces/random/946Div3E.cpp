/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jun, 2024 | 13:26:01
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXM = 51;
const int MAXH = 1e3+5;

ll dp[MAXM][MAXM*MAXH];

ll c[MAXM];
int h[MAXM*MAXH];


int m;
ll x;

int hsum = 0;

void maximize(ll &a, ll b) {
    a = max(a, b);
}
 
void solve() {
    cin >> m >> x;

    hsum = 0;

    for(int i=0;i<m;i++) {
        cin >> c[i] >> h[i];
        hsum += h[i];
    }

    for(int i=0;i<=m;i++) for(int j=0;j<=hsum;j++) dp[i][j] = -1;
    dp[0][0] = 0;


    for(int i=0;i<m;i++) {
        for(int j=0;j<=hsum;j++) {
            if(dp[i][j]==-1) continue;
            if(c[i]<=dp[i][j]) {
                maximize(dp[i+1][j+h[i]], dp[i][j]-c[i]+x);
            } 
            maximize(dp[i+1][j], dp[i][j] + x);
        }
    }

    int ans = 0;
    for(int i=0;i<=hsum;i++) {
        if(dp[m][i]!=-1) ans = i;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/