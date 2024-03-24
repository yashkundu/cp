/**
*   author: lazyhash(yashkundu)
*   created: 23 Feb, 2024 | 20:14:47
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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int startInd = 0;
    for(int i=0;i<n;i++) if(a[i]) {
        startInd = i;
        break;
    }

    int ans = 0;
    for(int i=n-1;i>startInd;i--) {
        if(!a[i]) continue;
        int j = i-1;
        while(j>startInd && a[j]) j--;
        if(j!=startInd) {
            a[j] = 1;
            a[i] = 0;
            ans++;
        }
    }

    cout << ans << "\n";


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