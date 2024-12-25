/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 20:06:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int a, b, c;

void solve() {
    cin >> a >> b >> c; 

    int mx = 0;

    for(int i=0;i<=5;i++) {
        for(int j=0;j+i<=5;j++) {
            for(int k=0;k+j+i<=5;k++) {
                mx = max(mx, (a+i)*(b+j)*(c+k));
            }
        }
    }

    cout << mx << "\n";


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