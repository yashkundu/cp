/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jun, 2024 | 19:58:22
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5+10;
const int MAXM = 30;

int pref[MAXN][MAXM] = {0}, suf[MAXN][MAXM] = {0};
int a[MAXN];
int pre[MAXN];

int n;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    pre[0] = a[0];
    for(int i=1;i<n;i++) pre[i] = pre[i-1]^a[i];



    for(int i=0;i<n;i++) {
        for(int j=0,f=1;j<MAXM;j++,f<<=1) {
            pref[i+1][j] = pref[i][j];
            if(pre[i]&f) pref[i+1][j]++;
        }
    }

    for(int j=0;j<MAXM;j++) suf[n][j] = 0;
    for(int i=n-1;i>=0;i--) {
        for(int j=0,f=1;j<MAXM;j++,f<<=1) {
            suf[i][j] = suf[i+1][j];
            if(pre[i]&f) suf[i][j]++;
        }
    }

    ll ans = 0;
    for(int i=0;i<n;i++) {
        int bit = 31 - __builtin_clz(a[i]);
        ans += 1LL*pref[i][bit]*suf[i][bit] + 1LL*(i+1-pref[i][bit])*(n-i-suf[i][bit]);
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