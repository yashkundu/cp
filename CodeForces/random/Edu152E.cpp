/**
*   author: lazyhash(yashkundu)
*   created: 14 Feb, 2024 | 19:20:08
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

const int N = 1e6+10;
int p[N];
 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> p[i];
    }

    vector<pair<int, int>> mxStck, mnStck;
    // to remove one additional if condition
    mnStck.emplace_back(0, -1);
    mxStck.emplace_back(n+1, -1);
    ll ans = 0;
    ll curAns = 0;

    set<pair<int, int>> curEvents;
    //  1 -> min, 0 -> max
    curEvents.emplace(-1, 2);

    // iterating over the right side of the current segments
    for(int i=0;i<n;i++) {
        // [l, i]

        // updating the mnStck
        while(mnStck.back().first>p[i]) {
            auto [el, ind] = mnStck.back();
            // delete this event from curEvents
            auto curIt = curEvents.find({ind, 1});
            auto prev = curIt;
            auto nxt = curIt;
            nxt++;
            prev--;
            curAns -= curIt->first-prev->first;
            if(nxt!=curEvents.end() && nxt->second) {
                curAns += curIt->first - prev->first;
            }
            curEvents.erase(curIt);
            mnStck.pop_back();
        }
        mnStck.emplace_back(p[i], i);
        curEvents.emplace(i, 1);


        // updateing the mxStck
        while(mxStck.back().first<p[i]) {
            auto [el, ind] = mxStck.back();
            auto curIt = curEvents.find({ind, 0});
            auto prev = curIt;
            auto nxt = curIt;
            prev--;
            nxt++;
            if(nxt!=curEvents.end() && nxt->second) {
                curAns += curIt->first-prev->first;
            }
            curEvents.erase(curIt);
            mxStck.pop_back();
        }
        mxStck.emplace_back(p[i], i);
        curEvents.emplace(i, 0);

        ans += curAns;
    }

    cout << ans << "\n";

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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