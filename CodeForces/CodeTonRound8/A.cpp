/**
*   author: lazyhash(yashkundu)
*   created: 30 Mar, 2024 | 20:08:20
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
    int n, k;
    cin >> n >> k;
    if(n==k) {
        for(int i=0;i<n;i++) cout << 1 << " ";
        cout << "\n";
        return;
    }
    if(k==1) {
        for(int i=0;i<n;i++) cout << i+1 << " ";
        cout << "\n";
        return;
    }
    cout << "-1\n";
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