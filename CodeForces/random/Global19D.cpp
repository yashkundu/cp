/**
*    author:  lazyhash(yashkundu)
*    created: 03 Oct, 2024 | 12:39:26
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 101;
const int inf = (int)1e9+10;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN*MAXN];


int n;

void minimize(int &x, int y) {
    x = min(x,y);
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<=n;i++) for(int j=0;j<=100*n;j++) dp[i][j] = inf;


    dp[0][0] = 0;

    int tot = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=100*i;j++) {
            if(dp[i][j]==inf) continue;
            minimize(dp[i+1][j+a[i]], dp[i][j] + a[i]*j + b[i]*(tot-j));
            minimize(dp[i+1][j+b[i]], dp[i][j] + b[i]*j + a[i]*(tot-j));
        }
        tot += (a[i]+b[i]);
    }


    int val = inf;
    for(int j=0;j<=100*n;j++) minimize(val, dp[n][j]);


    val = 2*val;
    for(int i=0;i<n;i++) val += (n-1)*(a[i]*a[i] + b[i]*b[i]);

    cout << val << "\n";









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