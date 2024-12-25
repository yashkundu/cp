/**
*    author:  lazyhash(yashkundu)
*    created: 21 Dec, 2024 | 00:39:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<ll, int>> v;
int n, b;
ll a;
 
void solve() {
    cin >> n;
    v.clear();

    for(int i=0;i<n;i++) {
        cin >> a >> b;
        pair<ll, int> p = make_pair(a, b);
        ll mx = 0;
        while(!v.empty() && (v.back().first<=p.first || v.back().second==p.second)) {
            auto tp = v.back();
            v.pop_back();
            if(tp.second==p.second) p.first += tp.first - mx;
            if(tp.second==p.second) mx = 0;
            else mx = tp.first;
        }
        v.push_back(p);
        cout << v[0].first << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/