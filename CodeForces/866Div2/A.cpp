/**
*   author: lazyhash(yashkundu)
*   created: 19 Apr, 2023 | 22:27:46
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
    if(s=="^") {
        cout << "1\n";
        return;
    }
    int n = s.size();
    int l = 0, r = n-1;
    while(l<n && s[l]=='_') l++;
    while(r>=0 && s[r]=='_') r--;
    if(l==n) {
        cout << (n+1) << "\n";
        return;
    }
    int ans = 0;
    ans += l+n-r-1;
    for(int i=l;i<=r;i++) {
        if(s[i]!='_') continue;
        int j = i;
        while(j<=r && s[j]=='_') j++;
        ans += (j-i-1);
        i = j - 1;
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