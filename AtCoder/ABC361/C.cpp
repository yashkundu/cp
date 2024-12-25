/**
*    author:  lazyhash(yashkundu)
*    created: 06 Jul, 2024 | 17:47:08
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
 
int n, k;
vector<int> a;

void solve() {
    cin >> n >> k;
    a.resize(n);
    
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    int del = n - k;

    int ans = 1e9;

    for(int i=0;i+del-1<n;i++) {
        ans = min(ans, a[i+del-1] - a[i]);
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