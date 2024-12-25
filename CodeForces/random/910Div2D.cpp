/**
*    author:  lazyhash(yashkundu)
*    created: 02 Jul, 2024 | 13:41:39
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5) + 10;

ll a[MAXN], b[MAXN];
vector<pair<ll, ll>> v;

ll tot = 0;
set<pair<ll, int>> st;

int n;

ll swapInds(int i, int j) {
    ll res = tot;
    res -= abs(v[i].first-v[i].second) + abs(v[j].first-v[j].second);
    res += abs(v[i].first-v[j].second) + abs(v[j].first - v[i].second);
    return res; 
}
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    v.resize(n);

    for(int i=0;i<n;i++) v[i] = {a[i], b[i]};

    sort(v.begin(), v.end());

    tot = 0;
    for(int i=0;i<n;i++) tot += abs(v[i].first-v[i].second);

    ll ans = tot;
    st.clear();

    for(int i=n-1;i>=0;i--) {
        if(!st.empty() && (*st.rbegin()).first>max(v[i].first, v[i].second)) {
            ans = max(ans, swapInds(i, (*st.rbegin()).second));
        }
        st.insert({min(v[i].first, v[i].second), i});
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