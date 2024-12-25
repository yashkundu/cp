/**
*    author:  lazyhash(yashkundu)
*    created: 23 Dec, 2024 | 00:39:15
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;
 
void solve() {
    cin >> n;
    cin >> s;

    int cntp = 0, cnts = 0;

    for(int i=0;i<n;i++) {
        if(s[i]=='p') cntp++;
        else if(s[i]=='s') cnts++;
    }

    if(cntp==0 || cnts==0) {
        cout << "YES\n";
        return;
    }


    if((cntp==1 && s[n-1]=='p') || (cnts==1 && s[0]=='s')) {
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/