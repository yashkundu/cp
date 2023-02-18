/**
*    author:  lazyhash(yashkundu)
*    created: 31 Jan, 2023 | 01:38:11
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    if(a[0]==a[n-1]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a[n-1] << " ";
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/