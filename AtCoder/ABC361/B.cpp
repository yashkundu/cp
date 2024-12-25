/**
*    author:  lazyhash(yashkundu)
*    created: 06 Jul, 2024 | 17:40:46
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int p1[6], p2[6];

 
void solve() {
    for(int i=0;i<6;i++) cin >> p1[i];
    for(int i=0;i<6;i++) cin >> p2[i];

    for(int i=0;i<3;i++) {
        int a = min(p1[i], p1[i+3]), b = max(p1[i], p1[i+3]);
        int c = min(p2[i], p2[i+3]), d = max(p2[i], p2[i+3]);
        if(min(b,d)<=max(a, c)) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";


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