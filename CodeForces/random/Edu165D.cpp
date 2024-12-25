/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jun, 2024 | 11:44:38
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

const int MAXN = 2e5+10;
ll suf[MAXN];
int a[MAXN], b[MAXN];

vector<pair<int, int>> v;
multiset<int> st;
 
int n,k;

void solve() {
    cin >> n >> k;
    v.clear();
    st.clear();

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++) {
        v.emplace_back(a[i], b[i]);
    }

    sort(v.begin(), v.end(), [] (const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second>p2.second;
    });

    suf[n] = 0;
    for(int i=n-1;i>=0;i--) {
        suf[i] = suf[i+1];
        if(v[i].second>v[i].first) suf[i] += v[i].second-v[i].first;
    }

    ll sum = 0;
    for(int i=0;i<k;i++) {
        st.insert(v[i].first);
        sum += v[i].first;
    }

    ll ans = 0;

    for(int i=k;i<n;i++) {
        ans = max(ans, suf[i] - sum);
        sum += v[i].first;
        st.insert(v[i].first);
        auto it = st.end();
        it--;
        sum -= *it;
        st.erase(it);
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