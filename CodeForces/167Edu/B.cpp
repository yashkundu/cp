/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jun, 2024 | 20:19:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
string a, b;
 
void solve() {
    cin >> a >> b;
    n = a.size(), m = b.size();

    int ans = 1e9;


    for(int i=0;i<m;i++) {
        int j = i;
        for(int k=0;k<n;k++) {
            if(j<m && b[j]==a[k]) j++;
        }
        ans = min(ans, (int)a.size() + i + m - j);
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