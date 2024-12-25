/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jul, 2024 | 14:48:24
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

int n;
vector<pair<int, int>> segs;
vector<int> ans;
vector<pair<int, int>> segl;
int b;

set<pair<int, int>> st;
 
void solve() {
    cin >> n;
    segs.resize(n);
    ans.resize(n);

    for(int i=1;i<=n;i++) {
        cin >> b;
        if(b==0) segs[i-1] = {i+1, n};
        else segs[i-1] = {i/(b+1)+1, i/b};
    }

    segl.clear();

    for(int i=0;i<n;i++) {
        segl.push_back({segs[i].first, i});
    }

    sort(segl.begin(), segl.end());


    int p1 = 0;
    st.clear();

    for(int i=1;i<=n;i++) {
        while(p1<n && segl[p1].first<=i) {
            st.insert({segs[segl[p1].second].second, segl[p1].second});
            p1++;
        }
        auto p = *st.begin();
        st.erase(st.begin());
        ans[p.second] = i;
    }


    for(int i=0;i<n;i++) cout << ans[i] << " ";
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