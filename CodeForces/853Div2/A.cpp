/**
*   author: lazyhash(yashkundu)
*   created: 25 Feb, 2023 | 19:58:31
**/
#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        if(__gcd(a[i], a[j])<=2) {
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