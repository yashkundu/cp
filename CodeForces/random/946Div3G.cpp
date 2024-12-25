/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jun, 2024 | 10:51:39
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

const int N = 2e5+10;
int c[N];

int n, x;
multiset<int> st;
 
void solve() {
    cin >> n >> x;
    st.clear();
    for(int i=0;i<n;i++) cin >> c[i];


    int ans = 0;
    int budget = 0;
    for(int i=0;i<n;i++) {
        if(c[i]<=budget) {
            ans++;
            budget -= c[i];
            st.insert(c[i]);
        } else if(!st.empty()){
            auto it = st.end();
            it--;
            int largest = *it;
            if(largest>c[i]) {
                st.erase(it);
                st.insert(c[i]);
                budget += largest - c[i];
            }
        }
        budget += x;
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/