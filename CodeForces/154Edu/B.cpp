/**
*   author: lazyhash(yashkundu)
*   created: 08 Sep, 2023 | 00:34:52
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
    string a, b;
    cin >> a >> b;

    int n = a.size();

    for(int i=0;i<n-1;i++) {
        if(a[i]=='0' && a[i+1]=='1' && a[i]==b[i] && a[i+1]==b[i+1]) {
            cout << "YES\n";
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