/**
*    author:  lazyhash(yashkundu)
*    created: 23 Oct, 2024 | 20:04:05
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
string a, b;

set<char> st;
 
void solve() {
    st.clear();
    cin >> n >> m;
    cin >> a >> b;
    for(int i=0;i<n;i++) st.insert(a[i]);
    for(int i=0;i<m;i++) st.insert(b[i]);

    if(st.size()==26) cout << "NO\n";
    else cout << "YES\n";

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