/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 17:34:59
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
int a[MAXN];

int n;
 
void solve() {
    cin >> n;
    for(int i=0;i<2*n;i++) cin >> a[i];
    int cnt = 0;
    for(int i=1;i<2*n-1;i++) if(a[i-1]==a[i+1]) cnt++;
    cout << cnt << "\n";
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