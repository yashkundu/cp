/**
*    author:  lazyhash(yashkundu)
*    created: 15 Aug, 2024 | 17:51:48
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


int n, m;
vector<int> a;
int k, d;

set<int> st;

 
void solve() {
    cin >> n >> m;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    st.clear();

    int mn = int(1e9)+10;

    for(int i=0;i<n;i++) {
        if(a[i]<mn) st.insert(i);
        mn = min(a[i], mn);
    }

    for(int i=0;i<m;i++) {
        cin >> k >> d;
        k--;
        a[k] -= d;
        auto it = st.lower_bound(k);
        if(it==st.begin() || a[*prev(it)]>a[k]) {
            st.insert(k);
            while(true) {
                auto it2 = st.upper_bound(k);
                if(it2==st.end()) break;
                if(a[*it2]<a[k]) break;
                st.erase(it2);
            }
        }

        cout << (int)st.size() << " ";
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