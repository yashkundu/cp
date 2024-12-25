/**
*    author:  lazyhash(yashkundu)
*    created: 16 Oct, 2024 | 20:08:40
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

    if(k==1) {
        int ans = 2*a[n-1] + a[n-2] + a[0];
        cout << ans << "\n";
        return;
    }

    int ans = a[0] + a[n-1] + a[n-2] + a[n-1-k];

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