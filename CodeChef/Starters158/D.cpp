/**
*    author:  lazyhash(yashkundu)
*    created: 30 Oct, 2024 | 20:35:15
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

int n;
ll a;
set<ll> st;


 
void solve() {

    cin >> n;
    st.clear();


    for(int i=0;i<n;i++) {
        cin >> a;
        while(st.find(a)!=st.end()) {
            st.erase(a);
            a *= 2;
        }
        st.insert(a);

        cout << st.size() << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/