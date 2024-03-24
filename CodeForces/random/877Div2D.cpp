/**
*   author: lazyhash(yashkundu)
*   created: 23 Feb, 2024 | 14:09:30
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
    string s;
    cin >> s;

    set<int> st;

    // ())()()()

    for(int i=0;i<n;i++) {
        if(i%2==0 && s[i]==')') st.insert(i);
        else if(i%2==1 && s[i]=='(') st.insert(i);
    }

    while(q--) {
        int ind;
        cin >> ind;
        ind--;
        if(s.size()%2) {
            cout << "NO\n";
            continue;
        }
        if((ind%2==0 && s[ind]==')') || (ind%2==1 && s[ind]=='(')) st.erase(ind);
        s[ind] = (s[ind]=='('?')':'(');
        if((ind%2==0 && s[ind]==')') || (ind%2==1 && s[ind]=='(')) st.insert(ind);
        if(st.empty() || ((*st.begin())%2==1 && (*st.rbegin())%2==0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
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