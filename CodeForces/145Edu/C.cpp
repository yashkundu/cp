/**
*   author: lazyhash(yashkundu)
*   created: 23 Mar, 2023 | 20:51:58
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n, 0);

    int sum = 0, ptr = 1;
    while(sum+ptr<=k) {
        ans[ptr-1] = 2;
        sum += ptr;
        ptr++;
    }

    assert(k-sum<=ptr);

    if(ptr<n+1 && k-sum>0) {
        int x = k - sum;
        ans[ptr-1] = -2*(ptr-x-1) - 1;
        ptr++;
    }

    while(ptr<=n) {
        ans[ptr-1] = -1000;
        ptr++;
    }


    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";





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