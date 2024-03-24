/**
*   author: lazyhash(yashkundu)
*   created: 27 May, 2023 | 17:47:57
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
    vector<int> p(n);
    int g = 0;
    for(int i=0;i<n;i++) {
        cin >> p[i];
        int x = abs(p[i]-i-1);
        g = gcd(g, x);
    }
    if(g==0) g = n;
    cout << g << "\n";

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