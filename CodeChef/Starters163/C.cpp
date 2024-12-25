/**
*    author:  lazyhash(yashkundu)
*    created: 04 Dec, 2024 | 20:30:56
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)3e5+10;

const int inf = (int)1e9;

int dp[MAXN][2];

int n;
string s, p;
map<char, char> mp; 



void solve() {
    cin >> n;
    cin >> s >> p;

    mp.clear();

    for(int i=0;i<13;i++) {
        mp[p[i]] = p[25-i];
        mp[p[25-i]] = p[i];
    }

    for(int i=0;i<n;i++) dp[i][0] = dp[i][1] = inf;


    dp[0][0] = 0;
    dp[0][1] = 1;


    for(int i=0;i<n-1;i++) {
        for(int j=0;j<2;j++) {
            if(dp[i][j]==inf) continue;
            char prv = s[i];
            if(j) prv = mp[prv];
            if(s[i+1]>=prv) dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
            if(mp[s[i+1]]>=prv) dp[i+1][1] = min(dp[i+1][1], dp[i][j]+1);
        }
    }

    int ans = min(dp[n-1][0], dp[n-1][1]);

    if(ans==inf) ans = -1;

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