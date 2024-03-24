/**
*   author: lazyhash(yashkundu)
*   created: 11 Nov, 2023 | 19:52:19
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
    vector<int> zerosDis;
    int oneCnt = 0;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='1') oneCnt++;
        else zerosDis.push_back(oneCnt);
    } 

    ll sum = 0;
    for(int i=1;i<=n;i++) {
        if(i>zerosDis.size()) {
            cout << "-1 ";  
        } else {
            sum += zerosDis[i-1];
            cout << sum << " ";
        }
    }

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