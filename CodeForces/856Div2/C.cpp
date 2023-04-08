/**
*   author: lazyhash(yashkundu)
*   created: 04 Mar, 2023 | 23:25:35
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int r=1;r<=n;r++) {
        int L = 0, R = r;
        while(L<R) {
            int mid = (L+R+1)/2;
            if(a[mid]<r-mid+1) L = mid;
            else R = mid-1;
        }
        cout << (r-L) << " ";
    }
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