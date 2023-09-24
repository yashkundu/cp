/**
*   author: lazyhash(yashkundu)
*   created: 16 Jul, 2023 | 11:55:09
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
    int n, k, x;
    cin >> n >> k >> x;
    if(x==1 && k==1) {
        cout << "NO\n";
        return;
    }
    if(x==1 && k==2 && n%2!=0) {
        cout << "NO\n";
        return;
    }
    if(x!=1) {
        cout << "YES\n";
        cout << n << "\n";
        for(int i=0;i<n;i++) cout << 1 << " ";
        cout << "\n";
        return;
    }
    cout << "YES\n";
    cout << n/2 << "\n";
    for(int i=0;i<n/2-1;i++) cout << 2 << " ";
    cout << (n - 2*(n/2-1)) << "\n";
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