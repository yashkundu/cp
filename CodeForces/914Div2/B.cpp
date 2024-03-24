/**
*   author: lazyhash(yashkundu)
*   created: 17 Dec, 2023 | 12:20:10
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
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<int> ans(n);
    vector<bool> isGood(n, 0);

    sort(a.begin(), a.end());

    ll sum = 0;
    for(int i=0;i<n-1;i++) {
        sum += a[i].first;
        if(sum>=a[i+1].first) isGood[i] = 1;
    }

    int lastBad = n-1;
    for(int i=n-1;i>=0;i--) {
        if(!isGood[i]) lastBad = i;
        ans[a[i].second] = lastBad+1;
    }

    for(int &x: ans) cout << x-1 << " ";
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