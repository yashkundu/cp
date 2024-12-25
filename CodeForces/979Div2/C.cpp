/**
*    author:  lazyhash(yashkundu)
*    created: 19 Oct, 2024 | 20:07:07
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
    cin >> s;

    if(s[0]=='1' || s[n-1]=='1') {
        cout << "YES\n";
        return;
    }

    
    for(int i=1;i<n;i++) {
        if(s[i]=='1' && s[i-1]=='1') {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";


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