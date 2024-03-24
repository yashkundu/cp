/**
*   author: lazyhash(yashkundu)
*   created: 31 Dec, 2023 | 23:12:29
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




bool selectFromSet(set<int> &s) {
    // selects a random value from the set and deletes that value from the set
    if(!s.size()) return false;
    auto it = s.begin();
    int val = *it;
    s.erase(it);
    cout << val << endl;
    return true;
}

 
void solve() {
    int n;
    cin >> n;
    int sx, sy;
    cin >> sx >> sy;

    set<int> evens, odds;

    for(int i=1;i<=n;i++) {
        int x, y;
        cin >> x >> y;
        int del = abs(x-sx) + abs(y-sy);
        if(del&1) odds.insert(i);
        else evens.insert(i);
    }

    string ans = "";
    if(evens.size()>=odds.size()) ans = "First";
    else ans = "Second";

    cout << ans << endl;

    set<int> &good = (ans=="First"?odds:evens);
    set<int> &bad = (ans=="First"?evens:odds);


    int p = (ans=="First"?0:1);


    for(int i=0;i<n;i++) {
        // simulating n turns
        if(i%2==p) {
            // my turn
            if(!selectFromSet(good)) selectFromSet(bad);
        } else {
            // other turn
            int x;
            cin >> x;
            if(x==-1) {
                exit(1);
            }
            if(good.count(x)) good.erase(x);
            else bad.erase(x);
        }
    }


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