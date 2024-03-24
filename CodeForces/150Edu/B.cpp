/**
*   author: lazyhash(yashkundu)
*   created: 12 Jun, 2023 | 20:27:48
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
    int q;
    cin >> q;
    bool hasChanged = false;
    int lastEl = -1;
    int firstEl = -1;
    for(int i=0;i<q;i++) {
        int x;
        cin >> x;
        if(!i) firstEl = x;
        if(!hasChanged) {
            if(x>=lastEl) {
                cout << 1;
                lastEl = x;
            } else {
                if(x<=firstEl) {
                    hasChanged = true;
                    cout << 1;
                    lastEl = x;
                } else {
                    cout << 0;
                }
            }
        } else {
            if(x>=lastEl && x<=firstEl) {
                cout << 1; 
                lastEl = x;
            } else {
                cout << 0;
            }
        }
    }
    cout << "\n";
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