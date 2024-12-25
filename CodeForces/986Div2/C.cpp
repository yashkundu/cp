/**
*    author:  lazyhash(yashkundu)
*    created: 11 Nov, 2024 | 01:35:17
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;

int n, m;
ll v;
ll a[MAXN];
int aux[MAXN];
 
void solve() {

    cin >> n >> m >> v;
    a[0] = 0;

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    for(int i=1;i<=m;i++) aux[i] = -1;
    aux[0] = n+1;

    ll cur = 0;
    int cnt = 0;
    for(int i=n;i>0;i--) {
        cur += a[i]-a[i-1];
        if(cur>=v) {
            cnt++;
            cur = 0;
            aux[cnt] = i;
        }
    }

    ll ans = -1;

    cur = 0;
    cnt = 0;

    for(int i=0;i<=n;i++) {
        if(i) cur += a[i]-a[i-1];
        if(cur>=v) {
            cur = 0;
            cnt++;
        }
        if(m-cnt>=0 && aux[m-cnt]>i) ans = max(ans, a[aux[m-cnt]-1]-a[i]);
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