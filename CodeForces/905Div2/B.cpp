/**
*   author: lazyhash(yashkundu)
*   created: 13 Nov, 2023 | 23:03:16
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    int minOps = 10;
    for(int x: a) {
        minOps = min(minOps, (k-(x%k))%k);
    }

    if(k==4 && minOps>0) {
        int even = 0, odd = 0;
        for(int x: a) if(x&1) odd++; else even++;
        if(even>1) minOps = 0;
        else if(even==1) minOps = 1;
        else minOps = min(minOps, 2);
    }

    cout << minOps << "\n";


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