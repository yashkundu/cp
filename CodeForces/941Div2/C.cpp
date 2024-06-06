/**
*   author: lazyhash(yashkundu)
*   created: 27 Apr, 2024 | 20:36:03
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
    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    a.resize(unique(a.begin(), a.end()) - a.begin());


    if(a.size()==1) {
        cout << "Alice\n";
        return;
    }

    if(a[0]>1) {
        cout << "Alice\n";
        return;
    }


    int cnt = 0;
    for(int i=1;i<n;i++) {
        if(a[i]-a[i-1]==1) cnt++;
        else break;
    }

    if(cnt!=a.size()-1) {
        cout << ((cnt&1)?"Alice":"Bob");
        cout << "\n";
        return;
    }

    cout << ((cnt&1)?"Bob":"Alice");
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