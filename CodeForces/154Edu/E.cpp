/**
*   author: lazyhash(yashkundu)
*   created: 10 Sep, 2023 | 19:58:28
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const ll mod = 998244353;

void add(ll &a, ll b) {
    a += b;
    if(a>=mod) a -= mod;
}

void sub(ll &a, ll b) {
    a -= b;
    if(a<0) a += mod;
}

ll mul(ll a, ll b) {
    return (a*b)%mod;
}

 
void solve() {
    int n, k;
    cin >> n >> k;

    // dp[i][x][c] -  the number of arrays of length i, with x distinct elements at last with a cost of c
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(k, vector<ll>(n/k+1, 0)));
    dp[0][0][0] = 1;


    for(int i=0;i<n;i++) {
        int curI = i&1;
        int nextI = curI^1;
        for(int x=0;x<k;x++) {
            for(int c=0;c<=n/k;c++) dp[nextI][x][c] = 0;
        }
        for(int x=0;x<k;x++) {
            for(int c=0;c<=n/k;c++) {
                if(!dp[curI][x][c]) continue;

                int nextX = (x+1)%k;

                // the ith elements is one of the (k-x) number which is not present in the distinct x numbers in the suffix
                add(dp[nextI][nextX][c + (nextX==0)], mul(k-x, dp[curI][x][c]));
                if(nextX<k-1) sub(dp[nextI][nextX+1][c+(nextX==0)], mul(k-x, dp[curI][x][c]));

                // the ith element if one of the x distinct numbers that are already present in the suffix
                // cost will remain same, just the number of distinct elements in the suffix will change from x, x-1, x-2, ... 1, all of them will increment by 1*previousDp
                // add(dp[i+1][x][c], dp[i][x][c])
                add(dp[nextI][1][c], dp[curI][x][c]);
                if(x<k-1) sub(dp[nextI][x+1][c], dp[curI][x][c]);
            }
        }
        for(int c=0;c<=n/k;c++) {
            for(int x=1;x<k;x++) {
                add(dp[nextI][x][c], dp[nextI][x-1][c]);
            }
        }
    }

    ll ans = 0;
    for(int x=0;x<k;x++) {
        for(int c=0;c<=n/k;c++) {
            add(ans, mul(c, dp[n&1][x][c]));
        }
    }

    cout << ans << "\n";



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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