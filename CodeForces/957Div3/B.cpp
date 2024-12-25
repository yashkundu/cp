/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 20:13:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<int> a;
 
void solve() {
    cin >> n >> k;
    a.resize(k);

    int mxInd = -1;

    for(int i=0;i<k;i++) {
        cin >> a[i];
        if(mxInd==-1 || a[i]>a[mxInd]) mxInd = i;
    }

    ll ans = 0;


    for(int i=0;i<k;i++) {
        if(i==mxInd) continue;
        ans += a[i]-1;
    }

    ans += (n-a[mxInd]);
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