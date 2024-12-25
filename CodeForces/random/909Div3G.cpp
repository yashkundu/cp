/**
*    author:  lazyhash(yashkundu)
*    created: 01 Jul, 2024 | 18:16:11
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

const int inf = int(1e9)+10;

struct SegTree{
    int n;
    vector<int> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4*n);
        for(int i=0;i<4*n;i++) tree[i] = inf;
    }

    void update(int ind, int val) {
        update(0, 0, n-1, ind, val);
    }

    void update(int v, int tl, int tr, int ind, int val) {
        if(ind<tl || ind>tr) return;
        if(tl==tr) {
            tree[v] = val;
            return;
        }
        int tm = (tl+tr)/2;
        update(2*v+1, tl, tm, ind, val);
        update(2*v+2, tm+1, tr, ind, val);
        tree[v] = min(tree[2*v+1], tree[2*v+2]);
    }

    int query(int ql, int qr) {
        return query(0, 0, n-1, ql, qr);
    }

    int query(int v, int tl, int tr, int ql, int qr) {
        if(tl>qr || tr<ql) return inf;
        if(tl>=ql && tr<=qr) return tree[v];
        int tm = (tl+tr)/2;
        return min(query(2*v+1, tl, tm, ql, qr), query(2*v+2, tm+1, tr, ql, qr));
    }
};

struct Query{
    int ql, qr, tin, tout, ind;
    Query(int ql, int qr, int tin, int tout, int ind): ql(ql), qr(qr), tin(tin), tout(tout), ind(ind) {}
    bool operator<(const Query &q) const {
        return tin>q.tin;
    }
};

const int MAXN = int(1e5) + 10;

vector<int> g[MAXN];
int p[MAXN], inds[MAXN];
int tin[MAXN], tout[MAXN];
bool ans[MAXN];

int n, q;
int u, v;
int l, r, x;
int timer = 0;

vector<Query> queries;


void dfs(int v, int p = -1) {
    tin[v] = timer++;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
    tout[v] = timer;
}

 
void solve() {
    cin >> n >> q;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    timer = 0;
    dfs(0);

    // debug(tin[0], tout[0], tin[1], tout[1], tin[2], tout[2]);

    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
        p[i] = tin[p[i]];
    }

    for(int i=0;i<n;i++) inds[p[i]] = i;


    SegTree tree(n);

    queries.clear();
    for(int i=0;i<q;i++) {
        cin >> l >> r >> x;
        l--, r--, x--;
        queries.push_back(Query(l, r, tin[x], tout[x], i));
    }

    sort(queries.begin(), queries.end());


    int j = n-1;
    for(auto q: queries) {
        while(j>=q.tin) {
            tree.update(inds[j], j);
            j--;
        }
        ans[q.ind] = tree.query(q.ql, q.qr) < q.tout;
    }

    for(int i=0;i<q;i++) {
        cout << (ans[i]?"YES":"NO") << "\n";
    }









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