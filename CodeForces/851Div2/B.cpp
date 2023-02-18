/**
*    author:  lazyhash(yashkundu)
*    created: 15 Feb, 2023 | 22:43:40
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    int a[2] = {0};
    int k = 0;
    for(int pv=1;n>0;n/=10,pv*=10) {
        int x = n%10;
        int num[2] = {0};
        if(x%2) {
            num[k]++;k = (k+1)%2;
        }
        num[0] += x/2;
        num[1] += x/2;
        a[0] += pv*num[0];
        a[1] += pv*num[1];
    }

    cout << a[0] << " " << a[1] << "\n";

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