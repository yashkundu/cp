/**
*   author: lazyhash(yashkundu)
*   created: 24 Feb, 2023 | 20:49:14
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for(int i=0;i<n;i++) cnt += s[i]=='1';

    bool is_cons = false;
    for(int i=0;i<n-1;i++) is_cons |= s[i]=='1' && s[i]==s[i+1];

    if(cnt&1) cout << "-1\n";
    else if(cnt!=2) cout << cnt/2 << "\n";
    else if(!is_cons) cout << 1 << "\n";
    else if(n==3) cout << "-1\n";
    else if(s=="0110") cout << "3\n";
    else cout << "2\n";

   


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