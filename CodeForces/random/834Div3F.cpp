/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jul, 2024 | 13:14:10
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

int n, p;
vector<int> a;

set<int> st;
 
void solve() {
    cin >> n >> p;
    a.resize(n);
    st.clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    int last = a[n-1];


    int l = -1, r = -1;

    for(int i=p-1;i>last;i--) {
        if(!st.count(i)) {
            r = i;
            break;
        }
    }

    for(int i=last-1;i>=0;i--) {
        if(!st.count(i)) {
            l = i;
            break;
        }
    }

    if(l==-1) {
        if(r==-1) cout << "0\n";
        else cout << r - last << "\n";
        return;
    }

    int ans = p - last;
    int carry = 1;
    a[n-1] = 0;
    for(int i=n-2;i>=0;i--) {
        a[i] += carry;
        carry = 0;
        if(a[i]==p) {
            a[i] = 0;
            carry = 1;
        }
    }

    if(carry) st.insert(carry);
    for(int i=0;i<n;i++) st.insert(a[i]);

    r = -1;
    for(int i=last-1;i>=0;i--) {
        if(!st.count(i)) {
            r = i;
            break;
        }
    }

    if(r!=-1) ans += r;

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