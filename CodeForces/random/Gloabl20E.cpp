/**
*   author: lazyhash(yashkundu)
*   created: 07 Mar, 2024 | 11:02:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int query(int w) {
    cout << "? " << w << endl;
    int h;
    cin >> h;
    return h;
}


 
void solve() {
    int n;
    cin >> n;

    int l = 1, r = 6e6;
    while(l<r) {
        int mid = (l+r)/2;
        int h = query(mid);
        if(h==1) r = mid;
        else l = mid + 1;
    }

    int s = l;

    int ans = s;
    for(int h=2;h<=n;h++) {
        // [s-h+1, s]
        // possible good area s/h*h
        // w = s/h
        int x = query(s/h);
        if(x==h) ans = min(ans, s/h*h);
    }

    cout << "! " << ans << endl;


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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/