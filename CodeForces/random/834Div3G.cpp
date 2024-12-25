/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jul, 2024 | 19:29:13
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

const int MAXN = int(2e5)+10;

int n;
int a[MAXN], b[MAXN];

set<int> st;
 
void solve() {
    cin >> n;
    for(int i=0;i<n/2;i++) {
        cin >> b[i];
    }

    st.clear();
    for(int i=1;i<=n;i++) st.insert(i);

    for(int i=0;i<n/2;i++) {
        if(st.find(b[i])==st.end()) {
            cout << "-1\n";
            return;
        }
        st.erase(b[i]);
    }



    for(int i=n/2-1;i>=0;i--) {
        int j = 2*(i+1)-1;
        a[j] = b[i];
        auto it = st.lower_bound(b[i]);
        if(it==st.begin()) {
            cout << "-1\n";
            return;
        }
        --it;
        a[j-1] = *it;
        st.erase(it);
    }

    for(int i=0;i<n;i++) cout << a[i] << " ";
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