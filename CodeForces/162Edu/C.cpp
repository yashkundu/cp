/**
*   author: lazyhash(yashkundu)
*   created: 23 Feb, 2024 | 20:44:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5+10;
ll c[N] = {0};
ll pre[N] = {0};
int ones[N] = {0};
 
void solve() {
    int n, q;
    cin >> n >> q;



    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=1;i<=n;i++) {
        pre[i] = pre[i-1] + c[i-1];
        ones[i] = ones[i-1];
        if(c[i-1]==1) ones[i]++;
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l==r) {
            cout << "NO\n";
            continue;
        }
        ll sum = pre[r] - pre[l-1];
        int numOnes = ones[r] - ones[l-1];
        if(2*numOnes + (r-l+1-numOnes)>sum) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
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