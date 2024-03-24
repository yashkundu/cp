/**
*   author: lazyhash(yashkundu)
*   created: 18 Apr, 2023 | 08:46:59
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll inf = 1e18;
const int N = 2e5+10;

vector<ll> a(N, 0);

// stores the ans for a subsegment
struct Node{
    // 1 - last edge of that side is taken, 0 - last edge of that side is not taken
    ll val[2][2];
    // contains info about the segment l-r
    // l,r denotes the index of edges not the vertices
    int l, r;
    Node() {
        ;
    }
    Node(int i) {
        // inf means not possible
        l = r = i;
        val[0][0] = 0;
        val[0][1] = val[1][0] = inf;
        val[1][1] = a[i];
    }
    
    friend Node merge(const Node &n1, const Node &n2) {
        // both end edges are not taken
        int l = n1.l, r = n2.r;
        Node node;
        node.l = n1.l;
        node.r = n2.r;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) {
            node.val[i][j] = min({n1.val[i][1]+n2.val[1][j], n1.val[i][0]+n2.val[1][j], n1.val[i][1]+n2.val[0][j], inf});
        }
        return node;
    }
};



struct SegTree{
    vector<Node> tree;
    int n;
    SegTree(int n) {
        tree.resize(4*n);
        this->n = n;
    }
    void buildTree(int ind, int l, int r, vector<ll> &a) {
        // debug(ind, l, r);
        if(l==r) {
            tree[ind] = Node(l);
            return;
        }
        int mid = (l+r)>>1;
        buildTree(2*ind+1, l, mid, a), buildTree(2*ind+2, mid+1, r, a);
        tree[ind] = merge(tree[2*ind+1], tree[2*ind+2]);
    }
    void build(vector<ll> &a) {
        buildTree(0, 0, n-1, a);
    }
    Node queryTree(int ind, int l, int r, int ql, int qr) {
        if(l>=ql && r<=qr) return tree[ind];
        int mid = (l+r)>>1;
        if(ql>mid) return queryTree(2*ind+2, mid+1, r, ql, qr);
        if(qr<=mid) return queryTree(2*ind+1, l, mid, ql, qr);
        return merge(queryTree(2*ind+1, l, mid, ql, qr), queryTree(2*ind+2, mid+1, r, ql, qr));
    }
    Node query(int ql, int qr) {
        return queryTree(0, 0, n-1, ql, qr);
    }
    void updateTree(int ind, int l, int r, int i) {
        if(l==r) {
            tree[ind] = Node(l);
            return;
        }
        if(i<l || i>r) return;
        int mid = (l+r)>>1;
        updateTree(2*ind+1, l, mid, i);
        updateTree(2*ind+2, mid+1, r, i);
        tree[ind] = merge(tree[2*ind+1], tree[2*ind+2]);
    }
    void update(int i) {
        updateTree(0, 0, n-1, i);
    }
};



 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++) cin >> a[i];
    int q;
    cin >> q;
    SegTree tree(n-1);
    tree.build(a);
    

    while(q--) {
        int k, x;
        cin >> k >> x;
        k--;
        a[k] = x;
        tree.update(k);
        cout << 2*tree.query(0, n-1).val[1][1] << "\n";
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