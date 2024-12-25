/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jun, 2024 | 09:23:59
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

const int MAXN = 1e5+10;
int a[MAXN] = {0};
int pref[MAXN] = {0};

int n;
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int mx = *max_element(a, a+n);


    int coeff = 0;
    for(int i=0;i<n;i++) {
        coeff = 0;
        if(i==0 || a[i]>a[i-1]) coeff++;
        if(i<n-1 && a[i]<a[i+1]) coeff--;
        pref[a[i]] += coeff;
    }

    for(int i=0;i<mx;i++) pref[i+1] += pref[i];

    ll ans = 0;
    for(int k=1;k<=mx;k++) {
        ans = 0;
        for(int i=1,val=1;i<=mx;i+=k,val++) {
            ans += 1LL*val*(pref[min(mx, i+k-1)] - pref[i-1]);
        }
        cout << ans << " ";
    }
    cout << "\n";


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