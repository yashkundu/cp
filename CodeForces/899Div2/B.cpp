/**
*   author: lazyhash(yashkundu)
*   created: 26 Sep, 2023 | 22:49:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 51;
 
void solve() {
    int n;
    cin >> n;
    vector<set<int>> sets;
    vector<int> cnt(K, 0);
    vector<int> tmpCnt(K, 0);
    vector<vector<int>> setIndices(K, vector<int>());

    for(int i=0;i<n;i++) {
        int sz;
        cin >> sz;

        set<int> st;
        for(int j=0;j<sz;j++) {
            int el;
            cin >> el;
            cnt[el]++;
            st.insert(el);
            setIndices[el].push_back(i);
        }
        sets.push_back(st);
    }

    int totEl = 0;
    for(int i=1;i<K;i++) totEl += (cnt[i]!=0);

    int ans = 0;
    for(int i=1;i<K;i++) {
        if(!cnt[i]) continue;
        fill(tmpCnt.begin(), tmpCnt.end(), 0);
        for(auto setInd: setIndices[i]) {
            for(auto el: sets[setInd]) tmpCnt[el]++;
        }
        int totElToBeRemoved = 0;
        for(int j=1;j<K;j++) {
            if(cnt[j] && cnt[j]==tmpCnt[j]) totElToBeRemoved++;
        }
        assert(totElToBeRemoved>0);
        ans = max(ans, totEl - totElToBeRemoved);
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