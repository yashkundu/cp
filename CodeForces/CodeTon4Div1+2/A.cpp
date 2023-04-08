/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2023 | 20:06:30
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    for(int i=0;i<n;i++) {
        if(a[i]<=i+1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";


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