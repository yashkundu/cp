/**
*    author:  lazyhash(yashkundu)
*    created: 23 Nov, 2024 | 20:16:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
 
void solve() {
    cin >> s;

    int n = s.size();

    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            cout << s[i] << s[i] << "\n";
            return;
        }
    }


    for(int i=2;i<n;i++) {
        if(s[i]!=s[i-2]) {
            cout << s[i-2] << s[i-1] << s[i] << "\n";
            return;
        }
    }

    cout << "-1\n";





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