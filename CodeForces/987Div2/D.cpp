/**
*    author:  lazyhash(yashkundu)
*    created: 16 Nov, 2024 | 21:21:24
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)5e5+10;

int n;
int a[MAXN], pa[MAXN], ans[MAXN];

 
void solve() {
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(i) pa[i] = max(a[i], pa[i-1]);
        else pa[i] = a[i];
    }

    pair<int, int> p = {MAXN, MAXN};
    for(int i=n-1;i>=0;i--) {
        ans[i] = pa[i];
        if(p.first<pa[i]) ans[i] = max(ans[i], ans[p.second]);
        if(a[i]<p.first) {
            p = {a[i], i};
        }
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
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