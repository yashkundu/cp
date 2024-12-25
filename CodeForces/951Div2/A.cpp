/**
*    author:  lazyhash(yashkundu)
*    created: 09 Jun, 2024 | 14:26:21
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 

const int N = 5e4+10;
int a[N];

int n;
 
void solve() {
    cin >> n;
    int mn = 1e9+10;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n-1;i++) mn = min(mn, max(a[i], a[i+1]));

    cout << mn - 1 << "\n";
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