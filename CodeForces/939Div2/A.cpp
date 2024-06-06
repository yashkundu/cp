/**
*   author: lazyhash(yashkundu)
*   created: 13 Apr, 2024 | 20:11:05
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
    int k, q;
    cin >> k >> q;

    int first = -1;
    for(int i=0;i<k;i++) {
        int a;
        cin >> a;
        if(first==-1) first = a;
    }
    for(int i=0;i<q;i++) {
        int x;
        cin >> x;
        cout << min(x, first-1) << " ";
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