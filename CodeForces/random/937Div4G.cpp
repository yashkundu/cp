/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jun, 2024 | 14:50:59
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

const int MAXN = 16;
int g[MAXN], w[MAXN];

map<string, int> mp;
int n;
string a, b;

vector<vector<bool>> dp;
 
void solve() {
    cin >> n;
    mp.clear();

    int cntr = 0;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        if(!mp.count(a)) mp[a] = cntr++;
        if(!mp.count(b)) mp[b] = cntr++;
        g[i] = mp[a];
        w[i] = mp[b];
    }

    dp.resize(1<<n);
    for(int i=0;i<(1<<n);i++) dp[i].resize(n);
    for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j] = 0;
    
    for(int j=0;j<n;j++) dp[1<<j][j] = 1;

    for(int mask=0;mask<(1<<n);mask++) {
        for(int j=0;j<n;j++) {
            if(!dp[mask][j]) continue;
            for(int k=0,f=1;k<n;k++,f<<=1) {
                if((mask&f)==0 && (g[j]==g[k] || w[j]==w[k])) dp[mask|f][k] = 1; 
            }
        }
    }

    int ans = n;
    for(int mask=0;mask<(1<<n);mask++) {
        for(int j=0;j<n;j++) {
            if(!dp[mask][j]) continue;
            ans = min(ans, n - __builtin_popcount(mask));
        } 
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