/**
*   author: lazyhash(yashkundu)
*   created: 12 Apr, 2023 | 20:19:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());




struct UnionFind{
    int n;
    vector<int> par, rank;
    UnionFind(int n) {
        this->n = n;
        par.resize(n);
        rank.resize(n);
        fill(rank.begin(), rank.end(), 0);
        std::iota(par.begin(), par.end(), 0);
    }
    int find(int v) {
        if(v==par[v]) return v;
        return par[v] = find(par[v]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u==v) return false;
        if(rank[u]>rank[v]) swap(u, v);
        par[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
    }
};

struct Node{
    int lca;
    Node(int lca) {
        this->lca = lca;
    }
    friend Node operator+(const Node &n1, const Node &n2) {
        return Node(get_lca(n1.lca, n2.lca));
    }
};

struct SegTree{
    vector<Node> tree;
    SegTree(int n) {
        tree.resize(4*n);
        build(0, 0, n-1);
    }
    void build(int ind, int l, int r) {
        if(l==r) {
            tree[ind] = Node(a[l]);
            return;
        }
        int mid = (l+r)>>1;
        build(2*ind+1, l, mid), build(2*ind+2, mid+1, r);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
    void modify(int ind, int l, int r, int i, int val) {
        if(l==r) {
            tree[ind] = Node(val);
            return;
        }
        if(i<l || i>r) return;
        int mid = (l+r)>>1;
        modify(2*ind+1, l, mid, i, val), modify(2*ind+2, mid+1, r, i, val);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
    Node query(int ind, int l, int r, int i, int j) {
        if(i>r || j<l) return Node(0);
        if(i>=l && j<=r) return tree[ind];
        int mid = (l+r)>>2;
        return query(2*ind+1, l, mid, i, j) + query(2*ind+2, mid+1, r, i, j);
    }
};



// Sig(phi(d))=n where d|n (divisor sum property of tf)               - nlogn
// phi(n) =  n*(1-1/p1)*(1-1/p2)*(1-1/p3) - nloglogn (extra division cost)
void sieve() {
    iota(phi.begin(), phi.end(), 0);
    for(int i=1;i<A;i++) {
        for(int j=2*i;j<A;j+=i) phi[j] -= phi[i];
    }
}

void init() {
    for(int i=2;i<A;i++) steps[i] = steps[phi[i]] + 1;
    for(int i=2;i<A;i++) {
        pre[i][0] = phi[i];
        for(int j=1;j<M;j++) {
            pre[i][j] = pre[pre[i][j-1]][j-1];
        }
    }
}

int get_lca(int u, int v) {
    if(!u) return v;
    if(!v) return u;
    if(steps[u]>steps[v]) swap(u, v);
    for(int j=M-1;j>=0;j--) if(steps[pre[v][j]]>=steps[u]) v = pre[v][j];
    if(u==v) return u;
    for(int j=M-1;j>=0;j--) if(pre[u][j]!=pre[v][j]) {
        u = pre[u][j];
        v = pre[v][j];
    }
    return pre[u][0];
}


const int N = 1e5+10;
const int M = 6;
const int A = 5e6+10;
vector<int> phi(A, 0);      // totient function
vector<int> steps(A, 0);    // no. of steps to reach 1
vector<vector<int>> pre(A, vector<int>(M, 1));      // totient function
vector<int> a(N, 0);

vector<int> nxtNOne(N, 0);
UnionFind dsu(N);
 
void solve() {
    sieve();
    iota(nxtNOne.begin(), nxtNOne.end(), 0);
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