/**
*   author: lazyhash(yashkundu)
*   created: 08 Apr, 2023 | 19:43:47
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int calc(int x, int y, int n, int m) {
    if(x==1 && y==1) return 2;
    if(x==n && y==m) return 2;
    if(x==1 && y==m) return 2;
    if(x==n && y==1) return 2;
    if(x==1 || x==n) return 3;
    if(y==1 || y==m) return 3;
    return 4;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << min(calc(x1, y1, n, m), calc(x2, y2, n, m)) << "\n";
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