/**
*   author: lazyhash(yashkundu)
*   created: 31 Mar, 2023 | 20:15:45
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n;
    cin >> n;
    if(n%2==0) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;

    while(n>1) {
        if((n+1)%4) {
            ans.push_back(1);
            n = (n+1)/2;
        } else {
            ans.push_back(2);
            n = (n-1)/2;
        }
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(int &x: ans) cout << x << " ";
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