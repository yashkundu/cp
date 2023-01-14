/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jan, 2023 | 11:02:26
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, k;
    cin >> n >> k;

    int pre = 0;
    int cnt = 0;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a==pre+1) {
            cnt++; 
            pre++;
        }
    }

    cout << (n-cnt+k-1)/k << "\n";

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/