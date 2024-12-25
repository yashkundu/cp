/**
*    author:  lazyhash(yashkundu)
*    created: 02 Oct, 2024 | 20:05:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<int> a;
 
void solve() {
    cin >> n >> k;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 2;
    bool b = true;
    for(int i=0;i<n;i++) if(a[i]!=k) b = false;


    if(b) {
        cout << "0\n";
        return;
    }


    b = true;
    for(int i=0;i<n;i++) if(a[i]%k) b = false;

    if(b) ans = 1;


    int l = -1, r = -1;
    for(int i=0;i<n;i++) if(a[i]!=k) {
        l = i;
        break;
    }

    for(int i=n-1;i>=0;i--) if(a[i]!=k) {
        r = i;
        break;
    }

    b = true;

    for(int i=l+1;i<=r;i++) if(a[i]!=a[l]) b = false;

    if(b) ans = 1;


    cout << ans << "\n";







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