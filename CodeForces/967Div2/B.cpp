/**
*    author:  lazyhash(yashkundu)
*    created: 20 Aug, 2024 | 20:26:25
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
 
void solve() {
    cin >> n;
    if(n%2==0) {
        cout << "-1\n";
        return;
    }

    for(int i=1;i<=n/2;i++) {
        cout << i << " " << (n-i+1) << " ";
    }
    cout << (n+1)/2 << "\n";

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