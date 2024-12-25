/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jun, 2024 | 17:31:38
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
string s;
 
void solve() {
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        cin >> s;
        if(s=="Takahashi") cnt++;
    }
    cout << cnt << "\n";
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