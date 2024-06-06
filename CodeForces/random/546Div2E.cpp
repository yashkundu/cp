/**
*   author: lazyhash(yashkundu)
*   created: 12 May, 2024 | 10:52:49
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



struct SegTree{
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
    void propagate(int v) {
        if(lazy[v]) {
            tree[2*v+1] += lazy[v];
            lazy[2*v+1] += lazy[v];
            tree[2*v+2] += lazy[v];
            lazy[2*v+2] += lazy[v];
        }
        lazy[v] = 0;
    }
    void build(int* a, int v, int tl, int tr) {
        if(tl==tr) {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(a, 2*v+1, tl, tm);
        build(a, 2*v+2, tm+1, tr);
        tree[v] = tree[2*v+1] + tree[2*v+2];
    }
    void build(int *a) {
        build(a, 0, 0, n-1);
    }
    void update(int v, int tl, int tr, int l, int r, ll val) {
        if(tl>r || tr<l) return;
        if(tl>=l && tr<=r) {
            tree[v] += val;
            lazy[v] += val;
            return;
        }
        int tm = (tl+tr)/2;
        propagate(v);
        update(2*v+1, tl, tm, l, r, val);
        update(2*v+2, tm+1, tr, l, r, val);
        tree[v] = tree[2*v+1] + tree[2*v+2];
    }
    void update(int l, int r, ll val) {
        update(0, 0, n-1, l, r, val);
    }
    ll query(int v, int tl, int tr, int l, int r) {
        if(tl>r || tr<l) return 0LL;
        if(tl>=l && tr<=r) return tree[v];
        propagate(v);
        int tm = (tl+tr)/2;
        return query(2*v+1, tl, tm, l, r) + query(2*v+2, tm+1, tr, l, r);
    }
    ll query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};


const int N = 1e5+10;
int a[N], k[N];

set<pair<int, int>> st;
vector<pair<int, int>> tempSegs;

int n, q;


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++) cin >> k[i];

    for(int i=0;i<n;i++) st.insert({i, i});

    SegTree stree(n);

    stree.build(a);

    cin >> q;

    while(q--) {
        char ch;
        cin >> ch;
        if(ch=='s') {
            int l, r;
            cin >> l >> r;
            l--, r--;
            ll ans = stree.query(l, r);
            cout << ans << "\n";
        } else {
            int i;
            ll x;
            cin >> i >> x;
            i--;

            // split the segment
            auto it = st.upper_bound({i, (int)1e9});
            it--;
            auto p = *it;
            st.erase(it);
            if(i!=p.first) st.insert({p.first, i-1});
            st.insert({i, p.second});

            tempSegs.clear();

            it = st.upper_bound({i, (int)1e9});
            it--;
            while(it!=st.end() && x) {
                auto [l, r] = *it;
                stree.update(l, r, x);
                if(r!=n-1) {
                    x = max(0LL, stree.query(r, r) + k[r] - stree.query(r+1, r+1));
                }
                tempSegs.push_back(*it);
                it++;
            }
            for(auto p: tempSegs) st.erase(p);
            st.insert({tempSegs[0].first, tempSegs.back().second});
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