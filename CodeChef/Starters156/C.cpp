/**
*    author:  lazyhash(yashkundu)
*    created: 16 Oct, 2024 | 21:11:06
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


struct Ftree{
    int n;
    vector<int> v;
    Ftree(int n) {
        this->n = n;
        v.resize(n+1);
        fill(v.begin(), v.end(), 0);
    }

    void update(int ind, int val) {
        for(;ind<=n;ind+=ind&-ind) v[ind] = max(v[ind], val);
    }

    int query(int ind) {
        int ans = 0;
        for(;ind>0;ind-=ind&-ind) ans = max(ans, v[ind]);
        return ans;
    }

};

int n;
vector<pair<int, int>> v;
 
void solve() {
    cin >> n;
    v.resize(n);

    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }


    sort(v.begin(), v.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second<p2.second;
    });

    Ftree ft(2*n);

    for(int i=0;i<n;i++) {
        auto [l, r] = v[i];
        int x = ft.query(l-1);
        ft.update(l, x+1);
    }

    int ans = ft.query(2*n);

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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/