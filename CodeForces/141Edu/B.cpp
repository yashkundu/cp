/**
*    author:  lazyhash(yashkundu)
*    created: 31 Jan, 2023 | 02:04:01
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    int first = 1, last = n*n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int k = (i%2==0)?(j):(n-j-1);
            a[i][k] = ((i+k)%2==0)?(first++):(last--);
        }
    }
    for(auto &v: a) {
        for(auto &x: v) cout << x << " ";
        cout << "\n";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/