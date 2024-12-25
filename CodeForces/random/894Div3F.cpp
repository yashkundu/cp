/**
*    author:  lazyhash(yashkundu)
*    created: 08 Jul, 2024 | 14:46:48
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 105;
const int MAXK = int(1e6)+10;

const int inf = int(1e9) + 10;

int s[MAXN];

int dp[2][MAXK];
ll tot = 0;

int cur, nxt;

int n;
ll w, f;

void minimize(int &a, int x) {
    a = min(a, x);
}


bool check(ll x, ll y) {
    int cur = n&1;
    for(int i=0;i<=min(tot, x);i++) if(dp[cur][i]<=y) return true;
    return false;
}


 
void solve() {
    cin >> w >> f;
    cin >> n;


    tot = 0;
    for(int i=0;i<n;i++) {
        cin >> s[i];
        tot += s[i];
    }

    for(int i=0;i<2;i++) for(int k=0;k<=tot;k++) dp[i][k] = inf;
    dp[0][0] = 0;


    for(int i=0;i<n;i++) {
        cur = i&1;
        nxt = 1^cur;
        for(int j=0;j<=tot;j++) {
            if(dp[cur][j]==inf) continue;
            minimize(dp[nxt][j+s[i]], dp[cur][j]);
            minimize(dp[nxt][j], dp[cur][j]+s[i]);
        }
        for(int j=0;j<=tot;j++) dp[cur][j] = inf;
    }


    int L = 0, R = int(1e6);

    while(R-L>1) {
        int mid = (L+R)/2;
        if(check(w*mid, f*mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";






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