/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 20:18:48
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

const int MAXN = 1e5+10;
int a[MAXN];

vector<int> v;

int n;
 
void solve() {
    cin >> n;
    v.clear();

    int mx = 0;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if(mx-a[i]) v.push_back(mx-a[i]);
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    ll cur = 0;

    int sz = v.size();

    for(int i=0;i<sz;i++) {
        ans += 1LL*(v[i]- cur)*(sz-i+1);
        cur += v[i]-cur;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/