/**
*    author:  lazyhash(yashkundu)
*    created: 17 Feb, 2023 | 17:59:44
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;


struct BIT {
    // 1 indexed
    vector<int> v;
    int n;
    BIT(int n) {
        this->n = n;
        v.assign(n+1, 0);
    }
    void update(int ind, int val) {
        for(;ind<=n;ind+=ind&(-ind)) v[ind] = max(v[ind], val);
    }
    int get(int ind) {
        int num = 0;
        for(;ind>0;ind-=ind&(-ind)) num = max(num, v[ind]);
        return num;
    }
};


 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<ll> pre(n+1, 0);
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i-1];

    vector<ll> v(n+1);

    for(int i=0;i<=n;i++) v[i] = pre[i];
    sort(v.begin(), v.end());

    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    
    BIT bit(n+1);
    vector<int> dp(n+2, 0);
    dp[0] = 0;
    // dp[i] = ans for a[1,2,3,4, ... i]

    for(int i=0;i<=n;i++) {
        int ind = lower_bound(v.begin(), v.end(), pre[i]) - v.begin() + 1;
        // the element is not taken in any segment
        dp[i] = (i>0)?dp[i-1]:0;
        // the element is taken in some segment
        int mx = max(0, bit.get(ind) - (n-i));
        dp[i] = max(mx, dp[i]);
        bit.update(ind, dp[i] + (n-i));
    }

    cout << dp[n] << "\n";





    


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