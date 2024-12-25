/**
*    author:  lazyhash(yashkundu)
*    created: 12 Oct, 2024 | 09:46:43
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;
 
void solve() {
    cin >> n >> m >> k;

    int del = n%m;
    int ptr = 1;

    for(int i=0;i<k;i++) {
        for(int j=0;j<del;j++) {
            cout << (n/m)+1 << " ";
            for(int x=0;x<n/m+1;x++) {
                cout << ptr << " ";
                ptr = (ptr)%n+1;
            }
            cout << "\n";
        }
        for(int j=0;j<m-del;j++) {
            cout << (n/m) << " ";
            for(int x=0;x<n/m;x++) {
                int cur = ptr + x + j*(n/m);
                cur = (cur-1)%n+1;
                cout << cur << " ";
            }
            cout << "\n";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/