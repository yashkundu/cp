/**
*   author: lazyhash(yashkundu)
*   created: 10 May, 2023 | 23:14:37
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, m;
    cin >> n >> m;
    if(n!=1 && n<=m) {
        cout << "No\n";
        return;
    }
    for(int i=2;i*i<=n;i++) {
        if(n%i==0 && i<=m) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/