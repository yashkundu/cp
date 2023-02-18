/**
*    author:  lazyhash(yashkundu)
*    created: 15 Feb, 2023 | 23:01:54
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    if(n%2==0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int k1 = n/2, k2 = 0;
    for(int i=1;i<=n;i++) {
        cout << k1+1 << " " << k2+1+n << "\n";
        k1 = (k1-1+n)%n;
        k2 = (k2+2)%n;
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