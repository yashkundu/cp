/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jan, 2023 | 20:52:51
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    int cnt = 0;
    for(auto &x: h){
        cin >> x;
        cnt += (x==1);
    }
    cout << (cnt/2) + (n-cnt+(cnt%2)) << "\n";
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