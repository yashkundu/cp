/**
*   author: lazyhash(yashkundu)
*   created: 19 Apr, 2023 | 23:14:01
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
    string s;
    cin >> s;
    s += s;
    int mx = 0;
    int n = s.size();
    for(int i=0;i<n;i++) {
        if(s[i]=='0') continue;
        int j = i;
        while(j<n && s[j]=='1') j++;
        mx = max(mx, j-i);
        i = j-1;
    }
    if(mx==n) {
        cout << 1LL*n*n/4 << "\n";
    }
    else if(mx&1) {
        cout << 1LL*(mx+1)/2*(mx+1)/2 << "\n";
    } else {
        cout << 1LL*(mx)/2*(mx/2+1) << "\n";
    }

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