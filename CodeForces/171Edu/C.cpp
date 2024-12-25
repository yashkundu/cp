/**
*    author:  lazyhash(yashkundu)
*    created: 28 Oct, 2024 | 21:25:02
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
vector<int> v;
string s;

set<int> st;
 
void solve() {
    cin >> n;
    cin >> s;

    ll tot = 1LL*n*(n+1)/2;

    st.clear();


    for(int i=n;i>0;i--) {
        if(s[i-1]=='1') st.insert(i);
        else if(!st.empty()){
            int x = *st.rbegin();
            tot -= x;
            st.erase(x);
        }
    }

    int m = st.size();


    for(int i=0;i<m/2;i++) {
        int x = *st.rbegin();
        tot -= x;
        st.erase(x);
    }

    cout << tot << "\n";












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