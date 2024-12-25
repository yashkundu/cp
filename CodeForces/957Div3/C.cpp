/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 20:21:09
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;
 
void solve() {
    cin >> n >> m >> k;

    for(int i=n;i>=k;i--) cout << i << " ";
    for(int i=k-1;i>m;i--) cout << i << " ";
    for(int i=1;i<=m;i++) cout << i << " ";
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