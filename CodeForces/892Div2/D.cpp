/**
*   author: lazyhash(yashkundu)
*   created: 03 Sep, 2023 | 12:57:32
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Portal {
    int ind;
    ll l, r, a, b;
    Portal(int ind, ll l, ll r, ll a, ll b): ind(ind), l(l), r(r), a(a), b(b) {}
    Portal() {}
};

bool operator<(const Portal& p1, const Portal& p2) {
    return p1.b<p2.r;
}
 
void solve() {
    int n;
    cin >> n;
    vector<Portal> v(n);
    for(int i=0;i<n;i++) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        v[i] = Portal(i, l, r, a, b);
    }
    sort(v.begin(), v.end());


    map<ll, int> rMapping;
    for(int i=0;i<n;i++) rMapping[v[i].b] = i;


    // for each portal tells the farthest point we can reach if we can use this portal
    vector<ll> fPoint(n, -1);
    fPoint[n-1] = v[n-1].b;

    // stores the inds of portals in decreasing order of l
    stack<int> st;
    st.push(n-1);

    for(int i=n-2;i>=0;i--) {
        while(!st.empty() && v[st.top()].l>v[i].b) st.pop();
        if(st.empty()) fPoint[i] = v[i].b;
        else fPoint[i] = fPoint[st.top()];
        while(!st.empty() && v[st.top()].l>=v[i].l) st.pop();
        st.push(i);
    }



    // calculate for each query
    vector<ll> cc;
    for(int i=0;i<n;i++) cc.push_back(v[i].l), cc.push_back(v[i].r);

    int m;
    cin >> m;

    vector<ll> x(m);
    for(int i=0;i<m;i++) {
        cin >> x[i];
        cc.push_back(x[i]);
    }



    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    auto getInd = [&cc] (ll x) {
        auto p = lower_bound(cc.begin(), cc.end(), x);
        return p-cc.begin();
    };

    vector<vector<int>> ops(cc.size(), vector<int>());
    for(int i=0;i<n;i++) {
        int indL = getInd(v[i].l), indR = getInd(v[i].r);
        ops[indL].push_back(v[i].b);
        ops[indR].push_back(-v[i].b);
    }


    vector<ll> maxRs(cc.size(), -1);
    multiset<ll> ms;

    

    for(int i=0;i<cc.size();i++) {
        for(int op: ops[i]) {
            if(op>0) ms.insert(op);
        }
        if(ms.empty()) maxRs[i] = -1;
        else maxRs[i] = *ms.rbegin();
        for(int op: ops[i]) {
            if(op<0) {
                auto it = ms.find(-op);
                assert(it!=ms.end());
                ms.erase(it);
            }
        }
    }



    for(int i=0;i<m;i++) {
        int ind = getInd(x[i]);
        int maxRPoint = maxRs[ind];
        if(maxRPoint==-1) {
            cout << x[i] << " ";
            continue;
        }
        ind = rMapping[maxRPoint];
        cout << max(fPoint[ind], x[i]) << " ";
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