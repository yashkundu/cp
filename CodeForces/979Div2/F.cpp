/**
*    author:  lazyhash(yashkundu)
*    created: 08 Nov, 2024 | 09:15:50
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;



struct SegTree{
    vector<int> tree;
    int n;
    SegTree(int n) {
        this->n = n;
        tree.resize(4*n);
        fill(tree.begin(), tree.end(), n);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if(tl==tr) {
            tree[v] = min(tree[v], val);
            return;
        }
        int tm = (tl+tr)/2;
        if(pos<=tm) update(2*v+1, tl, tm, pos, val);
        else update(2*v+2, tm+1, tr, pos, val);
        tree[v] = min(tree[2*v+1], tree[2*v+2]);
    }

    void update(int pos, int val) {
        update(0, 0, n-1, pos, val);
    }

    int query(int v,int tl, int tr, int l, int r) {
        if(l>r) return n;
        if(tl==l && tr==r) return tree[v];
        int tm = (tl+tr)/2;
        return min(query(2*v+1, tl, tm, l, min(tm, r)), query(2*v+2, tm+1, tr, max(tm+1, l), r));
    }

    int query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};



int n, q;
int a[MAXN], prv[MAXN], pos[MAXN], bad[MAXN];
bool ans[MAXN];

vector<pair<pair<int, int>, int>> v;
int l, r;
 
void solve() {
    cin >> n >> q;

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=1;i<=n;i++) pos[i] = -1;
    for(int i=0;i<n;i++) {
        prv[i] = pos[a[i]];
        pos[a[i]] = i;
    }



    SegTree sg(n);
    for(int i=0;i<n;i++) bad[i] = n;

    for(int i=n-1;i>=0;i--) {
        if(prv[i]>=0) {
            bad[prv[i]] = sg.query(prv[i]+1, i-1);
            sg.update(prv[i], i);
        }
    }

    v.clear();

    for(int i=0;i<q;i++) {
        cin >> l >> r;
        l--, r--;
        v.push_back({{l, r}, i});
    }


    sort(v.rbegin(), v.rend());

    int ptr = n;
    int curbad = n;


    for(auto p: v) {
        while(ptr>p.first.first) {
            ptr--;
            curbad = min(curbad, bad[ptr]);
        }
        if(p.first.second>=curbad) ans[p.second] = 0;
        else ans[p.second] = 1;
    }


    for(int i=0;i<q;i++) cout << (ans[i]?"YES":"NO") << "\n";















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