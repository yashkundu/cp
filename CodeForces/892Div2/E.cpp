/**
*   author: lazyhash(yashkundu)
*   created: 03 Sep, 2023 | 22:56:54
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3005;
const ll inf = 1e18;

ll dp1[N][N];
ll dp2[N][N][2][2];

 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    // dp1[i][j] - the maximum sum while using 1...i prefix and using segments of total length j
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp1[i][j] = -inf;
    dp1[0][0] = 0;

    // dp2[i][j] - the max value of (dp1[i-1][j-1], dp1[i-2][j-2], ....)
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int a=0;a<2;a++) for(int b=0;b<2;b++) dp2[i][j][a][b] = -inf;
    for(int p=0;p<2;p++) for(int q=0;q<2;q++) dp2[0][0][p][q] = 0;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            // the ith element is not included in anything
            dp1[i][j] = dp1[i-1][j];

            // the ith element if included in the last segment as the last element
            // will need the max(dp1[i-x][j-x] + f(i-x+1, i))
            for(int p=0;p<2;p++) for(int q=0;q<2;q++) {
                // let's consider only tpking the lpst of them
                if(i>0 && j>0) {
                    ll del = 0;
                    switch (2*p+q)
                    {
                    case 0:
                        del = (a[i-1] - b[i-1]) - (a[i]-b[i]); 
                        break;
                    case 1:
                        del = (a[i-1]+b[i-1]) - (a[i]+b[i]);
                        break;
                    case 2:
                        del = -(a[i-1]+b[i-1]) + (a[i]+b[i]);
                        break;
                    case 3:
                        del = -(a[i-1]-b[i-1]) + (a[i]-b[i]);
                        break;
                    }
                    dp2[i][j][p][q] = dp2[i-1][j-1][p][q] + del;
                    // one length segment is left, because there was no zero length segment in that
                    // dp2[i][j][p][q] = dp1p[i-1][j-1]
                    int x = b[i]>=a[i], y = b[i]>=a[i];
                    assert((2*x+y==0) || (2*x+y==3));
                    switch (2*x+y)
                    {
                    case 0:
                        dp2[i][j][0][0] = max(dp2[i][j][0][0], dp1[i-1][j-1] + 2*(b[i]-a[i]));
                        dp2[i][j][0][1] = max(dp2[i][j][0][1], dp1[i-1][j-1] + 0);
                        break;
                    case 3:
                        dp2[i][j][1][0] = max(dp2[i][j][1][0], dp1[i-1][j-1] + 0);
                        dp2[i][j][1][0] = max(dp2[i][j][1][0], dp1[i-1][j-1] + 2*(a[i]-b[i]));
                        break;
                    }
                }
                    
            }
            // on the basis of current p, q
            int f = b[i]>=a[i];
            dp1[i][j] = max(dp1[i][j], dp2[i][j][0][f]);
            dp1[i][j] = max(dp1[i][j], dp2[i][j][1][f]);
        }
    }

    cout << dp1[n][k] << "\n";

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