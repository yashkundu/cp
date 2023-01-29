/**
*    author:  lazyhash(yashkundu)
*    created: 26 Jan, 2023 | 21:20:49
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &x: p)
        cin >> x;
    
    int l = 1, r = n;
    int cur = 1;
    for(int x: p) {
        if(x<l || x>r) continue;
        if(x==cur) cur++;
        else {
            if(x<=(n+1)/2) 
                l = x, r = n - (x-1), cur = l+1;
            else 
                l = n - (x-2), r = x-1, cur = max(l, cur);
        } 
    }

    cout << (l-1) << "\n";


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