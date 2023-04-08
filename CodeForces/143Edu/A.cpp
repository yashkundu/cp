/**
*   author: lazyhash(yashkundu)
*   created: 21 Feb, 2023 | 13:22:57
**/
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s2.begin(), s2.end());
    s1 = s1 + s2;
    int cnt = 0;
    for(int i=0;i<s1.size()-1;i++) cnt += s1[i]==s1[i+1];
    cout << ((cnt<=1)?"YES":"NO");
    cout << "\n";
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