/**
*   author: lazyhash(yashkundu)
*   created: 04 Mar, 2023 | 23:06:42
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
 
void solve() {
    int n;
    cin >> n;
    int k = n/2;
    vector<string> v;
    for(int i=0;i<2*n-2;i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    string s1, s2;
    for(int i=0;i<2*n-2;i++) if(v[i].size()==k) s1 = v[i];
    for(int i=2*n-2;i>=0;i--) if(v[i].size()==k) s2 = v[i];

    reverse(s2.begin(), s2.end());
    if(s1==s2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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