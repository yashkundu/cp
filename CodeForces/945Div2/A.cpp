/**
*   author: lazyhash(yashkundu)
*   created: 17 May, 2024 | 20:09:28
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
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;


    int ans = -1;

    for(int d1=0;d1<=min(p1, p2);d1++) {
        for(int d2=0;d2<=min(p2, p3); d2++) {
            int newP1 = p1 - d1, newP2 = p2 - d1 - d2, newP3 = p3 - d2;
            if(!(newP1>=0 && newP2>=0 && newP3>=0)) continue;
            if(newP2&1) continue;
            if(newP1%2!=newP3%2) continue;
            int del = min(newP1, newP3);
            if((newP1-del)&1) del++;
            ans = max(ans, d1+d2+del);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/