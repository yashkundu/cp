/**
*   author: lazyhash(yashkundu)
*   created: 15 Feb, 2024 | 22:10:03
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
    int k, x, a;
    cin >> k >> x >> a;
    int totLoss = 0;

    for(int i=0;i<x;i++) {
        // curGain should be > totLoss
        // if I can't this if not good input
        // maxGain -> y*(k-1)
        int curY = (totLoss+k-1)/(k-1);
        if(curY>a) {
            cout << "NO\n";
            return;
        }
        totLoss += curY;
        a -= curY;
    }

    // totGain > totLoss
    if((totLoss+k-1)/(k-1)<=a) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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