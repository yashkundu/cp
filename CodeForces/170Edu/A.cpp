/**
*    author:  lazyhash(yashkundu)
*    created: 14 Oct, 2024 | 20:06:55
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s, t;
int n, m;
 
void solve() {
    cin >> s >> t;
    n = s.size();
    m = t.size();

    int ans = 0;

    int i=0;
    for(i=0;i<min(n, m);i++) {
        if(s[i]!=t[i]) break;
    }

    
    ans += (i+1) + (m+n) - 2*i;
    ans = min(ans, n+m);

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