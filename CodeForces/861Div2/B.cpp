/**
*   author: lazyhash(yashkundu)
*   created: 01 Apr, 2023 | 20:39:45
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin >> v[i][j];
    }

    vector<vector<ll>> sV(m);

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) sV[i].push_back(v[j][i]);
    }

    for(vector<ll> &v: sV) sort(v.begin(), v.end());

    for(vector<ll> &v: sV) {
        for(int i=n-2;i>=0;i--) v[i] += v[i+1];
    }

    ll ans = 0;
    for(vector<ll> &v: sV) {
        for(int i=0;i<n-1;i++) {
            ans += v[i+1] - 1LL*(v[i]-v[i+1])*(n-i-1); 
        }
    }

    cout << ans << "\n";

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