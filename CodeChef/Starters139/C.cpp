/**
*    author:  lazyhash(yashkundu)
*    created: 19 Jun, 2024 | 20:44:33
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

const int MAXN = 101;
ll a[MAXN];
ll pref[MAXN];
ll sum = 0;
ll c;
ll first;
int n; 

void solve() {
    cin >> n >> c;

    sum = 0;
    cin >> first;
    pref[0] = 0;
    for(int i=1;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a+1, a+n);
    for(int i=1;i<n;i++) pref[i] = pref[i-1] + a[i];


    int ans = n;

    for(int i=0;i<n-1;i++) {
        if(min((first+pref[i])*(sum-pref[i]), (first+sum-pref[n-1-i])*pref[n-1-i])<=c) {
            ans = 1+i;
            break;
        }
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