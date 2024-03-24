/**
*   author: lazyhash(yashkundu)
*   created: 19 Sep, 2023 | 23:41:26
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
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> v;
    v.push_back(y);
    for(int i=1;i<n;i++) v.push_back(v.back()-i);
    if(v.back()<x) {
        cout << "-1\n";
        return;
    }
    cout << x << " ";
    for(auto it=v.rbegin()+1;it!=v.rend();it++) cout << (*it) << " ";
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