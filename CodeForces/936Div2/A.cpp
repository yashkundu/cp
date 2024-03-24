/**
*   author: lazyhash(yashkundu)
*   created: 22 Mar, 2024 | 20:07:51
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
    int md = a[(n+1)/2-1];
    int cnt = 0;
    int i = (n+1)/2-1;
    while(i<n && a[i]==md) {
        cnt++;
        i++;
    }
    cout << cnt << "\n";
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