/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jun, 2024 | 17:53:20
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

const int MAXN = 2e5+10;
ll a[MAXN], b[MAXN];

int n, m;
 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int j=0;j<m;j++) cin >> b[j];

    sort(a, a+n);
    sort(b, b+m);


    ll ans = 0;

    int ptr = 0;

    for(int i=0;i<m;i++) {
        while(ptr<n && a[ptr]<b[i]) ptr++;
        if(ptr==n) {
            cout << "-1\n";
            return;
        }
        ans += a[ptr++];
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/