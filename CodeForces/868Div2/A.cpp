/**
*   author: lazyhash(yashkundu)
*   created: 27 Apr, 2023 | 20:07:32
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
    for(int i=0;i<=n;i++) {
        int curAns = i*(i-1)/2 + (n-i)*(n-i-1)/2;
        if(curAns==k) {
            cout << "YES\n";
            for(int j=0;j<i;j++) cout << "1 ";
            for(int j=i;j<n;j++) cout << "-1 ";
            cout << "\n";
            return;
        }
    }

    cout << "NO\n";
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