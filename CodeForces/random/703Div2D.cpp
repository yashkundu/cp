/**
*   author: lazyhash(yashkundu)
*   created: 25 Mar, 2024 | 16:57:37
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
int a[N];
int pre[N], newA[N];

int n, k;

// check if the ans is atleast x
bool check(int x) {
    for(int i=0;i<n;i++) {
        if(a[i]>=x) newA[i] = 1;
        else newA[i] = -1;
    }
    pre[0] = 0;
    for(int i=0;i<n;i++) pre[i+1] = pre[i] + newA[i];

    int mnPrefix = 1e9;
    for(int i=1;i<=n;i++) {
        if(i-k>=0) mnPrefix = min(mnPrefix, pre[i-k]);
        if(pre[i]-mnPrefix>0) return true;
    }
    return false;
}



 
void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    while(l<r) {
        int mid = (l+r+1)/2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";

    
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