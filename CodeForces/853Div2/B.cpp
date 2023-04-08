/**
*   author: lazyhash(yashkundu)
*   created: 25 Feb, 2023 | 20:08:10
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

    int cur = 0;
    int cnt = 0;


    for(int i=0;i<(n+1)/2;i++) {
        int j = n-1-i;
        if(s[i]==s[j]) {
            cur = 0;
        } else {
            if(cur==0) cnt++;
            cur = 1;
        }
    }

    if(cnt>1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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