/**
*   author: lazyhash(yashkundu)
*   created: 25 Nov, 2023 | 22:42:43
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> ops;

    set<int> st;

    for(int i=0;i<q;i++) {
        int x;
        cin >> x;
        if(st.find(x)==st.end()) {
            ops.push_back(x);
            st.insert(x);
        }
    }


    for(int op: ops) {
        int val = 1<<op;
        for(int i=0;i<n;i++) {
            if(a[i]%val==0) {
                a[i] += (val/2);
            }
        }
    }

    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }

    cout << "\n";


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