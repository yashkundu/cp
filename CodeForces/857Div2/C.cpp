/**
*   author: lazyhash(yashkundu)
*   created: 11 Mar, 2023 | 08:42:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 205;
ll a[N][N] = {0};
 
void solve() {
    int n, m;
    cin >> n >> m;


    for(int i=0;i<n;i++) for(int j=0;j<m;j++) a[i][j] = 0;

    cout << n*m << "\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) a[i][j] ^= i;
    }
    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            a[i][j] ^= (j*256);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << a[i][j] << " ";
        cout << "\n";
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