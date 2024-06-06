/**
*   author: lazyhash(yashkundu)
*   created: 13 Apr, 2024 | 20:16:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
int cnt[N] = {0};
int a[N];
 
void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ans = 0;
    for(int i=0;i<n;i++) if(cnt[a[i]]==2) ans++;
    ans = ans/2;

    for(int i=0;i<n;i++) cnt[a[i]] = 0;
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