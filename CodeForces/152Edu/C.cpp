/**
*   author: lazyhash(yashkundu)
*   created: 13 Aug, 2023 | 23:17:32
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> l(m), r(m);
    for(int i=0;i<m;i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    vector<int> lf(n), rg(n);
    lf[0] = -1;
    for(int i=0;i<n;i++) {
        if(i) lf[i] = lf[i-1];
        if(s[i]=='0') lf[i] = i;
    }
    rg[n-1] = n;
    for(int i=n-1;i>=0;i--) {
        if(i<n-1) rg[i] = rg[i+1];
        if(s[i]=='1') rg[i] = i;
    }

    set<pair<int, int>> st;
    for(int i=0;i<m;i++) {
        int x = rg[l[i]], y = lf[r[i]];
        if(x>y) {
            st.emplace(-1, -1);
        } else {
            st.emplace(x, y);
        }
    }

    cout << st.size() << "\n";


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