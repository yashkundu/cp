/**
*   author: lazyhash(yashkundu)
*   created: 15 Nov, 2023 | 22:07:24
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
    vector<int> a(n);
    for(int &x: a) cin >> x;

    int cnt = 1;
    for(int i=1;i<n;i++) if(a[i]==a[0]) cnt++;

    set<int> st;
    for(int i=0;i<n;i++) st.insert(a[i]);

    if(st.size()==1) {
        cout << "Yes\n";
        return;
    }

    if(st.size()==2) {
        if(n&1 && (cnt==n/2 || cnt==n/2+1)) {
            cout << "Yes\n";
            return;
        }
        if(!(n&1) && (cnt==n/2)) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";


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