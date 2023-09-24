/**
*   author: lazyhash(yashkundu)
*   created: 16 May, 2023 | 21:35:05
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
    int l = 0, r = 0;

    set<int> st;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x==-1) l++;
        else if(x==-2) r++;
        else st.insert(x);
    }

    int ans = 0;

    int cnt = 0;
    for(auto it=st.begin();it!=st.end();it++) {
        int ind = *(it);
        int leftOnes = cnt;
        int rightOnes = st.size()-cnt-1;
        ans = max(ans, 1 + leftOnes + min(l, ind-1-leftOnes) + rightOnes + min(r, m-ind-rightOnes));
        cnt++;
    }
   
    int lAns = l + st.size();
    if(st.count(m)) lAns--;
    int rAns = r + st.size();
    if(st.count(1)) rAns--;
    
    ans = max(ans, lAns);
    ans = max(ans, rAns);

    ans = min(ans, m);

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