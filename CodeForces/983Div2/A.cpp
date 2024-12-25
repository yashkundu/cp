/**
*    author:  lazyhash(yashkundu)
*    created: 01 Nov, 2024 | 20:08:13
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int a;
 
void solve() {
    cin >> n;
    int cnt = 0;
    for(int i=0;i<2*n;i++) {
        cin >> a;
        if(a) cnt++;
    }

    cout << (cnt&1) << " ";


    int ans = cnt;
    if(cnt>=n) {
        ans = cnt - 2*(cnt-n);
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