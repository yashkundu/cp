/**
*   author: lazyhash(yashkundu)
*   created: 05 Mar, 2024 | 09:48:50
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> cnt;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    set<pair<int, int>> s1, s2;
    for(auto p: cnt) s2.emplace(p.second, p.first);

    int sumF = 0;

    int ans = 1e9;
    int holes = 0;

    for(int mex=0;mex<=n;mex++) {
        // modify the s1 and s2
        // remove mex-1, because we are considering [mex, n] as one 
        if(s1.find({cnt[mex-1], mex-1})!=s1.end()) {
            sumF -= cnt[mex-1];
            s1.erase({cnt[mex-1], mex-1});
        } 
        if(s2.find({cnt[mex-1], mex-1})!=s2.end()) {
            s2.erase({cnt[mex-1], mex-1});
        }
        while(!s2.empty() && sumF + (s2.begin()->first) <= k) {
            sumF += s2.begin()->first;
            auto p = s2.begin();
            s1.emplace(p->first, p->second);
            s2.erase(p);
        }
        if(k<holes) break;
        int curDiff = mex + s2.size();
        if(mex==0) curDiff = max(1, (int)s2.size());

        ans = min(ans, curDiff - mex);
        if(!cnt[mex]) holes++;

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