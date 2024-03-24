/**
*   author: lazyhash(yashkundu)
*   created: 12 Aug, 2023 | 23:39:57
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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].first = a[i].first%k;
        if(!a[i].first) a[i].first = k;
        a[i].second = -i;
    }
    sort(a.begin(), a.end());
    for (auto it=a.rbegin();it!=a.rend();it++) {
        cout << -(it->second)+1 << " ";
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