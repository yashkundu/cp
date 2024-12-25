/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 21:07:17
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 5005;

int a[MAXN];
int dp[MAXN][MAXN];

int n;

vector<int> v;


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+n);
    v.clear();

    for(int i=0;i<n;) {
        int j = i;
        while(j<n && a[i]==a[j]) j++;
        v.push_back(j-i);
        i = j;
    }

    int sz = v.size();
    for(int i=0;i<=sz;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;


    for(int i=0;i<sz;i++) {
        for(int j=0;j<=n;j++) {
            // dp[i][j]
            int left = i - dp[i][j] - j;
            if(left<0) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(left>=v[i]) dp[i+1][j+v[i]] = max(dp[i+1][j+v[i]], dp[i][j]+1);
        }
    }

    int ans = 0;
    for(int i=0;i<=sz;i++) for(int j=0;j<=n;j++) ans = max(ans, dp[i][j]);

    ans = sz - ans;

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