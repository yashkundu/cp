/**
*    author:  lazyhash(yashkundu)
*    created: 09 Nov, 2024 | 20:25:43
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
string s,t;
 
void solve() {
    cin >> n;
    cin >> s >> t;

    int cnt0=0, cnt1 = 0;

    for(int i=0;i<n;i++) {
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }


    for(int i=0;i<n-1;i++) {
        if(!(cnt0 && cnt1)) {
            cout << "NO\n";
            return;
        }
        if(t[i]=='1') {
            cnt0--;
        }
        else {
            cnt1--;
        }
    }

    cout << "YES\n";



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