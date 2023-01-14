/**
*    author:  lazyhash(yashkundu)
*    created: 07 Jan,2023 | 15:05:28
**/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> d1, d2;
int n;

bool valid(int dis) {

    // either sum = d, else dif = d, no third case
    // take max >= dis and iterate and choose the max-dis of other array

    vector<int> ans;
    multiset<int, greater<int>> m1, m2;

    for(int d: d1) m1.insert(d);
    for(int d: d2) m2.insert(d);

    auto maxOne = [](multiset<int, greater<int>> &m) {
        return m.empty()?-1:(*m.begin());
    };

    auto maxBoth = [&]() {
        return max(maxOne(m1), maxOne(m2));
    };

    while(maxBoth() > dis) {
        bool fromOne = maxOne(m1)>maxOne(m2);
        auto &mFarthest = fromOne?m1:m2;
        auto &mClosest = fromOne?m2:m1;

        int value = *mFarthest.begin();

        // mf mc        px
        if(!mClosest.count(value-dis)) return false;
        mFarthest.erase(mFarthest.find(value));
        mClosest.erase(mClosest.find(value - dis));

        if(fromOne) ans.push_back(value);
        else ans.push_back(dis-value);
    }

    vector<int> l1, l2;

    for(int m: m1) l1.push_back(m);
    for(int m: m2) l2.push_back(m);

    sort(l1.begin(), l1.end());
    sort(l2.rbegin(), l2.rend());

    for(int i=0;i<l1.size();i++) {
        if(l1[i]+l2[i]!=dis) return false;
        else ans.push_back(l1[i]);
    }

    sort(ans.begin(), ans.end());
    int del = max(-1*ans[0], 0);

    cout << "YES\n";

    for(int a: ans) cout << a+del << " ";
    cout << "\n";
    cout << (del) << " " << (del + dis) << "\n";

    return true;


}

void solve() {
    cin >> n;

    d1.resize(n); d2.resize(n);

    for(int &d: d1) cin >> d;
    for(int &d: d2) cin >> d;

    // h1 h2 h3 h4 |p1| h5 h6 h7 h8 |p2| h9 h10

    for(int i=0;i<n;i++) {
        if(valid(d1[0]+d2[i])) return;
        if(valid(abs(d1[0]-d2[i]))) return;
    }
    cout << "NO\n";

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