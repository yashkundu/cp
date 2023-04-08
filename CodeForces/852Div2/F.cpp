/**
*    author:  lazyhash(yashkundu)
*    created: 20 Feb, 2023 | 11:44:11
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int inf = 1e9+100;

template<class T>
struct SegTree{
public:
    SegTree(int n, T (*f) (T, T), T def_val) : cmb(f), dVal(def_val), n(n) {
        tree.assign(4*n, def_val);
    }
    void build(vector<T> a) {
        build(a, 0, n-1, 0);
    }
    T query(int q1, int q2) {
        return query(q1, q2, 0, n-1, 0);
    }
    void update(int ind, T val) {
        update(0, n-1, 0, ind, val);
    }
private:
    vector<T> tree;
    int n;
    T (*cmb) (T, T);
    T dVal;
    // O(N)
    void build(vector<T> a, int t1, int t2, int tnode) {
        if(t1==t2) {
            tree[tnode] = a[t1];
            return;
        }
        int mid = (t1+t2)/2;
        build(a, t1, mid, 2*tnode+1), build(a, mid+1, t2, 2*tnode+2);
        tree[tnode] = cmb(tree[2*tnode+1], tree[2*tnode+2]);
    }
    // O(LOG(N))
    T query(int q1, int q2, int t1, int t2, int tnode) {
        if(q1>t2 || q2<t1) return dVal;
        if(q1<=t1 && q2>=t2) {
            return tree[tnode];
        }
        int mid = (t1+t2)/2;
        T q = cmb(query(q1, q2, t1, mid, 2*tnode+1), query(q1, q2, mid+1, t2, 2*tnode+2));
        return q;
    }
    // O(LOG(N))
    void update(int t1, int t2, int tnode, int ind, T val) {
        if(ind<t1 || ind>t2) return;
        if(t1==t2) {
            tree[tnode] = cmb(tree[tnode], val);
            return;
        } 
        int mid = (t1+t2)/2;
        update(t1, mid, 2*tnode+1, ind, val), update(mid+1, t2, 2*tnode+2, ind, val);
        tree[tnode] = cmb(tree[2*tnode+1], tree[2*tnode+2]);
    }
};
 
 
void solve() {
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
        x--;
    }

    vector<pair<int, int>> segs[n];

    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        segs[r].push_back({l, i});
    }

    SegTree<int> rIndex(n, [](int x, int y) {return max(x, y);}, -1);
    // dp[i] - stores the minimum difference of a[i] with the elements on its right which we have considered upto this point
    SegTree<int> dp(n, [](int x, int y) {return min(x, y);}, inf);

    vector<int> ans(q);
    for(int i=0;i<n;i++) {
        int R = n-1;

        while(true) {
            int ind = rIndex.query(a[i], R);
            if(ind==-1) break;
            dp.update(ind, a[ind]-a[i]);
            R = a[i] + (a[ind]-a[i])/2;
        }
        int L = 0;
        while(true) {
            int ind = rIndex.query(L, a[i]);
            if(ind==-1) break;
            dp.update(ind, a[i]-a[ind]);
            L = a[i] - (a[i]-a[ind])/2;
        }
        for(auto seg: segs[i]) {
            ans[seg.second] = dp.query(seg.first, i);
        }
        rIndex.update(a[i], i);
    }

    for(int &x: ans) cout << x << "\n";

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