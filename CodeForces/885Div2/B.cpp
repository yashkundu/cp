/**
*   author: lazyhash(yashkundu)
*   created: 23 Jul, 2023 | 12:10:15
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
    int n, k;
    cin >> n >> k;
    vector<int> inds[k];
    for(auto &v: inds) v.push_back(-1);
    for(int i=0;i<n;i++) {
        int c;
        cin >> c;
        inds[c-1].push_back(i);
    }
    for(auto &v: inds) v.push_back(n);
    int ans = 1e9;
    for(auto &v: inds) {
        int m1 = 0, m2 = 0;
        for(int i=1;i<v.size();i++) {
            int del = v[i] - v[i-1] - 1;
            if(del>m1) {
                m2 = m1;
                m1 = del;
            } else if(del>m2) {
                m2 = del;
            }
        }
        ans = min(ans, max(m1/2, m2));
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