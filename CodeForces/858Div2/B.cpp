/**
*   author: lazyhash(yashkundu)
*   created: 20 Mar, 2023 | 00:48:45
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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int cnt0 = 0, cnt1 = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt0 += a[i]==0;
        cnt1 += a[i]==1;
    }

    if(2*cnt0-1<=n) {
        cout << "0\n";
        return;
    }

    if(cnt0+cnt1!=n || cnt1==0) {
        cout << "1\n";
        return;
    }

    cout << "2\n";

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