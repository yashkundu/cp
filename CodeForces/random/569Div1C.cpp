/**
*   author: lazyhash(yashkundu)
*   created: 09 May, 2024 | 16:06:44
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


struct SegTree{
    int n;
    vector<int> tree, lazy;
    SegTree(int n) {
        this->n = n;
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void propagate(int v, int tl, int tr) {
        if(tl!=tr) {
            tree[2*v+1] += lazy[v];
            lazy[2*v+1] += lazy[v];
            tree[2*v+2] += lazy[v];
            lazy[2*v+2] += lazy[v];
        }
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        if(tl>r || tr<l) return;
        if(tl>=l && tr<=r) {
            tree[v] += val;
            lazy[v] += val;
            return;
        }
        propagate(v, tl, tr);
        int tm = (tl+tr)>>1;
        update(2*v+1, tl, tm, l, r, val);
        update(2*v+2, tm+1, tr, l, r, val);
        tree[v] = max(tree[2*v+1], tree[2*v+2]);
    }


    int get(int v, int tl, int tr) {
        if(tl==tr) return tl;
        int tm = (tl+tr)>>1;
        propagate(v, tl, tr);
        if(tree[2*v+2]>0) return get(2*v+2, tm+1, tr);
        else return get(2*v+1, tl, tm);
    }
};



const int N = 3e5+10;
int a[N], b[N];
int t[N], p[N], s[N];


const int MAXV = 3*N;

int u = 0;
int val[MAXV];
SegTree tree(MAXV);

int n, m, q;


void add1(int x) {
    tree.update(0, 0, MAXV-1, 0, x, 1);
}

void del1(int x) {
    tree.update(0, 0, MAXV-1, 0, x, -1);
}

void update1(int ind, int x) {
    del1(a[ind]);
    a[ind] = x;
    add1(a[ind]);
}

void add2(int x) {
    tree.update(0, 0, MAXV-1, 0, x, -1);
}

void del2(int x) {
    tree.update(0, 0, MAXV-1, 0, x, 1);
}

void update2(int ind, int x) {
    del2(b[ind]);
    b[ind] = x;
    add2(b[ind]);
}

int get() {
    if(tree.tree[0]>0) {
        return tree.get(0, 0, MAXV-1);
    }
    return -1;
}

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        val[u++] = a[i];
    }
    for(int i=0;i<m;i++) {
        cin >> b[i];
        val[u++] = b[i];
    }

    cin >> q;
    for(int i=0;i<q;i++) {
        cin >> t[i] >> p[i] >> s[i];
        p[i]--;
        val[u++] = s[i];
    }




    // mapping values
    sort(val, val+u);
    u = unique(val, val+u) - val;

    for(int i=0;i<n;i++) a[i] = lower_bound(val, val+u, a[i]) - val;
    for(int i=0;i<m;i++) b[i] = lower_bound(val, val+u, b[i]) - val;
    for(int i=0;i<q;i++) s[i] = lower_bound(val, val+u, s[i]) - val;



    for(int i=0;i<q;i++) {
        if(t[i]==1) update1(p[i], s[i]);
        else update2(p[i], s[i]);
        int ans = get();
        if(ans==-1) cout << "-1\n";
        else cout << val[ans] << "\n";
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