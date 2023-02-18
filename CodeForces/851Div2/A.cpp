/**
*    author:  lazyhash(yashkundu)
*    created: 15 Feb, 2023 | 22:30:38
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for(int &x: a) {
        cin >> x;
        cnt += (x==2);
    }
    if(cnt&1) {
        cout << "-1\n";
        return;
    }
    cnt /= 2;
    int k = 0;
    while(cnt!=0) 
        cnt -= (a[k++]==2); 
    
    cout << max(k, 1) << "\n";

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