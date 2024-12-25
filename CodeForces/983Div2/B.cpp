/**
*    author:  lazyhash(yashkundu)
*    created: 01 Nov, 2024 | 20:16:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
 
void solve() {
    cin >> n >> k;
    if(n==1) {
        cout << "1\n1\n";
        return;
    } 


    if(k==1 || k==n) {
        cout << "-1\n";
        return;
    }


    if(k%2==0) {
        cout << "3\n";
        cout << "1 " << k << " " << (k+1) << "\n";
        return;
    }

    cout << "5\n";
    cout << "1 " << (k-1) << " " << k << " " << (k+1) << " " << (k+2) << "\n";



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