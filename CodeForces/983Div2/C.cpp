/**
*    author:  lazyhash(yashkundu)
*    created: 01 Nov, 2024 | 20:36:38
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

int n;
vector<int> a;
 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());


    int ans = n-1;

    int l = 0;
    for(int i=0;i<n;i++) {
        while(l<i-1 && a[l]+a[l+1]<=a[i]) l++;
        ans = min(ans, l+n-i-1);
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