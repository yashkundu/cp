/**
*   author: lazyhash(yashkundu)
*   created: 21 Apr, 2023 | 13:16:47
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
const int N = 2e5+10;
vector<int> a(N), b(N);
 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int l = 0, r = n-1;
    while(l<n && a[l]==b[l]) l++;
    while(r>=0 && a[r]==b[r]) r--;
    assert(l<=r);
    while(l>0 && b[l-1]<=b[l]) l--;
    while(r<n-1 && b[r]<=b[r+1]) r++;
    cout << (l+1) << " " << (r+1) << "\n";

    
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