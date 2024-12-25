/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jul, 2024 | 20:15:18
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
string s, t;
 
void solve() {
    cin >> n >> s >> t;

    int first = n;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            first = i;
            break;
        }
    }

    for(int i=0;i<first;i++) {
        if(t[i]!='0') {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";




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