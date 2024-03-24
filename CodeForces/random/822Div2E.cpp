/**
*   author: lazyhash(yashkundu)
*   created: 02 Mar, 2024 | 16:13:27
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 351;
int a[N][N];
int b[N];
 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j] = (i*j)%n;

    for(int j=0;j<n;j++) {

        int del = (b[j]-a[j][j]+n)%n;
        for(int i=0;i<n;i++) {
            a[i][j] = (a[i][j]+del)%n;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << a[i][j] << " ";
        cout << "\n";
    }


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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