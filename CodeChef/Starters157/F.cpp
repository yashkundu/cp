/**
*    author:  lazyhash(yashkundu)
*    created: 23 Oct, 2024 | 21:09:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;
 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];



    int mn = (int)1e9+10, mnind = -1;
    int mx = 0, mxind = -1;

    for(int i=0;i<n;i++) {
        if(a[i]<=mn) {
            mn = a[i];
            mnind = i;
        }
        if(a[i]>=mx) {
            mx = a[i];
            mxind =i;
        }
    }

    if(mxind<mnind) {
        cout << "-1\n";
        return;
    }

    int cur = n;

    cout << n-2 << "\n";

    while(cur>2) {
        cout << "1 ";
        if(cur&1) cout << cur;
        else cout << cur-1;
        cout << "\n";
        cur--;
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