/**
*   author: lazyhash(yashkundu)
*   created: 26 Nov, 2023 | 20:07:11
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='#') continue;
        int j = i;
        while(j<n && s[j]==s[i]) j++;
        ans += min(j-i, 2);
        if(j-i>2) {
            cout << "2\n";
            return;
        }
        i = j-1;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/