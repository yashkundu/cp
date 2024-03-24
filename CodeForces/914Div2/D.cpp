/**
*   author: lazyhash(yashkundu)
*   created: 23 Dec, 2023 | 17:48:51
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <stack>
#include <algorithm>

 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
int a[N], b[N], gL[N], gR[N];
vector<int> posa[N], posb[N];
set<int> ss;



bool checkRange(int a, int b, set<int> s) {
    return s.upper_bound(b)==s.lower_bound(a);
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=1;i<=n;i++) posa[i].clear(), posb[i].clear();


    for(int i=0;i<n;i++) posb[b[i]].push_back(i);
    for(int i=0;i<n;i++) posa[a[i]].push_back(i);


    stack<int> st;
    for(int i=0;i<n;i++) {
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(st.empty()) gL[i] = -1;
        else gL[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(st.empty()) gR[i] = n;
        else gR[i] = st.top();
        st.push(i);
    }

    ss.clear();

    for(int el=1;el<=n;el++) {
        for(int p: posb[el]) {
            if(a[p]>el) {
                cout << "NO\n";
                return;
            }
            else if(a[p]==el) {
                continue;
            }
            // calculate
            bool isThisGood = false;
            auto rightElIt = lower_bound(posa[el].begin(), posa[el].end(), p);
            if(rightElIt!=posa[el].end()) {
                // checking for right el
                int ind = posa[el][rightElIt - posa[el].begin()];
                if(gL[ind]<p && checkRange(p, ind, ss)) {
                    isThisGood = true;
                }
            }
            if(rightElIt!=posa[el].begin()) {
                // checking for left el
                int ind = posa[el][rightElIt - posa[el].begin() - 1];
                if(gR[ind]>p && checkRange(ind, p, ss)) {
                    isThisGood = true;
                }
            }
            if(!isThisGood) {
                cout << "NO\n";
                return;
            }
        }
        for(int p: posb[el]) {
            ss.insert(p);
        }
    }

    cout << "YES\n";

    
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