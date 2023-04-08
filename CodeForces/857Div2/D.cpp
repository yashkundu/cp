/**
*   author: lazyhash(yashkundu)
*   created: 11 Mar, 2023 | 12:10:04
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

const int N = 5e5+100;
const int inf = 1e9+100000;
vector<int> a(N, 0), b(N, 0);
vector<int> v[N];
vector<int> mx(N, -inf);
 
void solve() {
    int n;
    cin >> n;

    vector<int> mping;

    for(int i=0;i<n;i++) {
        cin >> a[i];
        mping.push_back(a[i]);
        cin >> b[i];
    }

    for(int i=0;i<=n;i++) {
        mx[i] = -inf;
        v[i].clear();
    }

    sort(mping.begin(), mping.end());
    mping.resize(distance(mping.begin(), unique(mping.begin(), mping.end())));

    int m = mping.size();

    for(int i=0;i<n;i++) {
        int ind = lower_bound(mping.begin(), mping.end(), a[i]) - mping.begin();
        v[ind].push_back(b[i]);
        mx[ind] = max(mx[ind], b[i]);
    }

    for(int i=m-2;i>=0;i--) mx[i] = max(mx[i], mx[i+1]);

    int ans = inf;

    set<int> st;

    for(int i=0;i<m;i++) {
        // mping[i] is the maximum in a side
        int cur_ans = abs(mx[i+1]-mping[i]);
        if(v[i].size()>1) for(int x: v[i]) if(x>mx[i+1]) cur_ans = min(cur_ans, abs(x-mping[i]));
        auto ptr = st.lower_bound(mping[i]);
        if(ptr!=st.end() && (*ptr)>mx[i+1]) cur_ans = min(cur_ans, abs((*ptr)-mping[i]));
        if(ptr!=st.begin()) {
            ptr--;
            if((*ptr)>mx[i+1]) cur_ans = min(cur_ans, abs((*ptr)-mping[i]));
        }
        ans = min(ans, cur_ans);
        for(int x: v[i]) {
            st.insert(x);
        }
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