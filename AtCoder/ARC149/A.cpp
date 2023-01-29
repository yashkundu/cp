/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jan, 2023 | 17:39:07
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    ll n, m;
    cin >> n >> m;

    ll rem = 0;
    int ones = 0;
    pair<int, int> ans(0, 0);
    while(ones<n) {
        // new rem
        // 111*10 + 1
        rem = ((rem*10)+1)%m;
        ones++;
        for(int j=1;j<=9;j++) {
            if((rem*j)%m==0) {
                ans = {ones, j};
            }
        }
    }

    if(ans.first==0) {
        cout << "-1\n";
        return; 
    }

    for(int i=0;i<ans.first;i++) cout << ans.second;
    cout << "\n";


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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/