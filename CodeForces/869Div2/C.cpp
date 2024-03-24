/**
*   author: lazyhash(yashkundu)
*   created: 01 May, 2023 | 10:06:29
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
    int n, q;
    cin >> n >> q;
    

    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];
    // 1, 2, 3, 4, 6, 4, 3, 2, 4
    vector<bool> good(n+1);
    for(int i=2;i<=n;i++) {
        if(a[i-1]<a[i]) {
            good[i] = good[i-1] = true;
        }
    }


    vector<int> cnt(n+2, 0);
    for(int i=1;i<=n;i++) cnt[i] = cnt[i-1] + good[i];

    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l==r) {
            cout << "1\n";
            continue;
        }
        int ans = cnt[r] - cnt[l-1] + !good[l] + !good[r];
        cout << ans << "\n";
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