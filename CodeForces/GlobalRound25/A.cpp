/**
*   author: lazyhash(yashkundu)
*   created: 06 Apr, 2024 | 20:10:43
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

    int cnt = 0;
    for(int i=0;i<n;i++) if(s[i]=='1') cnt++;


    bool isAdj = false;
    for(int i=0;i<n-1;i++) if(s[i]=='1' && s[i+1]=='1') isAdj = true;

    if(cnt==2 && isAdj) {
        cout << "NO\n";
        return;
    }


    if(cnt&1) cout << "NO\n";
    else cout << "YES\n";

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