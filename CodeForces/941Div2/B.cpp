/**
*   author: lazyhash(yashkundu)
*   created: 27 Apr, 2024 | 20:14:35
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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> c(n, vector<bool>(m, 0));

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<m;j++) c[i][j] = (s[j]=='B');
    }

    if(c[0][0]==c[n-1][m-1]) {
        cout << "YES\n";
        return;
    }

    bool f1 = false, f2 =false, f3 = false, f4 = false;
    for(int j=0;j<m;j++) {
        if(c[0][j]!=c[0][0]) f1 = true;
        if(c[n-1][j]!=c[n-1][m-1]) f3 = true;
    }

    for(int i=0;i<n;i++) {
        if(c[i][0]!=c[0][0]) f2 = true;
        if(c[i][m-1]!=c[n-1][m-1]) f4 = true;
    }

    if((f1&&f2) || (f3&&f4)) {
        cout << "YES\n";
        return;
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/