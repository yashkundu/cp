/**
*   author: lazyhash(yashkundu)
*   created: 17 Dec, 2023 | 12:09:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int, int>> v = {{1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
 
void solve() {
    int a, b;
    cin >> a >> b;

    int kx, ky, qx, qy;
    cin >> kx >> ky;
    cin >> qx >> qy;

    set<pair<int, int>> st1, st2;
    for(auto [i, j]: v) {
        st1.emplace(kx+i*a, ky+j*b);
        st1.emplace(kx+i*b, ky+j*a);
        st2.emplace(qx+i*a, qy+j*b);
        st2.emplace(qx+i*b, qy+j*a);
    }

    int ans = 0;
    for(auto p: st2) if(st1.count(p)) ans++;

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