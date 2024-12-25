/**
*    author:  lazyhash(yashkundu)
*    created: 24 Dec, 2024 | 20:24:36
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, d;
 
void solve() {
    cin >> n >> d;

    cout << "1 ";

    if(d%3==0 || n>=3) cout << "3 ";

    if(d==5) cout << "5 ";

    if(d==7 || n>=3) cout << "7 ";

    if(d%9==0 || (d%3==0 && n>=3) || n>=6) cout << "9 ";

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/