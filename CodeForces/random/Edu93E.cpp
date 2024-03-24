/**
*   author: lazyhash(yashkundu)
*   created: 20 Feb, 2024 | 16:56:13
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

 
void solve() {
    int n;
    cin >> n;
    set<int> st[2];
    st[0].insert(0);

    set<int, greater<int>> topK, topAll;

    ll sumLSpells = 0;
    ll sumTopKSpells = 0;
    ll sumSpells = 0;

    for(int i=0;i<n;i++) {
        int t, d;
        cin >> t >> d;
        if(d>0) {
            // inserting to the set
            sumSpells += d;
            if(t==1) sumLSpells += d;
            st[t].insert(d);
            sumTopKSpells += d;
            topK.insert(d);
            int el = *(topK.rbegin());
            sumTopKSpells -= el;
            topK.erase(el);

            topAll.insert(d);
            if(t==1) {
                // k increases by one
                if(topK.empty()) {
                    int el = *(topAll.begin());
                    sumTopKSpells += el;
                    topK.insert(el);
                } else {
                    int smallestEl = *(topK.rbegin());
                    auto it = topAll.find(smallestEl);
                    ++it;
                    sumTopKSpells += *it;
                    topK.insert(*it);
                }
            }
            
        } else {
            // removing from the set
            d *= -1;
            sumSpells -= d;
            if(t==1) sumLSpells -= d;
            st[t].erase(d);
            auto it = topK.find(d);
            if(it!=topK.end()) {
                sumTopKSpells -= *it;
                topK.erase(it);
            }
            topAll.erase(d);
            if(it!=topK.end() && t==0) {
                // k increases by one
                if(topK.empty()) {
                    int el = *(topAll.begin());
                    sumTopKSpells += el;
                    topK.insert(el);
                } else {
                    int smallestEl = *(topK.rbegin());
                    auto it = topAll.find(smallestEl);
                    ++it;
                    sumTopKSpells += *it;
                    topK.insert(*it);
                }
            } else if(it==topK.end() && t==1) {
                int smallestEl = *(topK.rbegin());
                sumTopKSpells -= smallestEl;
                topK.erase(smallestEl);
            }
        }

        ll newSumTopKSpells= sumTopKSpells;
        if(sumTopKSpells==sumLSpells && sumTopKSpells) {
            newSumTopKSpells -= *(st[1].begin());
            newSumTopKSpells += *(st[0].rbegin());
        }
        ll ans = sumSpells + newSumTopKSpells;
        cout << ans << "\n";
    }

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