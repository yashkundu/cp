/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 20:22:25
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, x, y;
vector<int> ans;
 
void solve() {
    cin >> n >> x >> y;
    ans.resize(n+1);

    for(int i=y;i<=x;i++) ans[i] = 1;
    for(int i=y-1;i>0;i--) {
        if((y-i)&1) ans[i] = -1;
        else ans[i] = 1;
    }

    for(int i=x+1;i<=n;i++) {
        if((i-x)&1) ans[i] = -1;
        else ans[i] = 1;
    }

    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";

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