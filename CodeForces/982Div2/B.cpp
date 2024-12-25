/**
*    author:  lazyhash(yashkundu)
*    created: 26 Oct, 2024 | 20:33:09
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2005;

int n;
int a[MAXN];


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    int ans = MAXN;


    for(int i=0;i<n;i++) {
        int curans = i;
        for(int j=i+1;j<n;j++) if(a[j]>a[i]) curans++;
        ans = min(ans, curans);
    }

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