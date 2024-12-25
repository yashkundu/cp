/**
*    author:  lazyhash(yashkundu)
*    created: 27 Sep, 2024 | 20:26:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
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

const int inf = (int)1e9+10;

struct SegTree{
    vector<int> tree;
    vector<int> lazy;
    int n;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }


    void build(int v, int tl, int tr, vector<int> a) {
        if(tl==tr) {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(2*v+1, tl, tm, a);
        build(2*v+2, tm+1, tr, a);
        tree[v] = min(tree[2*v+1], tree[2*v+2]);
    }


    void build(vector<int> a) {
        build(0, 0, n-1, a);
    }


    void propagate(int v, int tl, int tr) {
        if(!lazy[v]) return;
        if(tl!=tr) {
            lazy[2*v+1] += lazy[v];
            lazy[2*v+2] += lazy[v];
        }
        tree[v] += lazy[v];
        lazy[v] = 0;
    }
    
    int query(int l, int r) {
        if(l>r) return inf;
        return query(0, 0, n-1, l, r);
    }

    int query(int v, int tl, int tr, int ql, int qr) {
        propagate(v, tl, tr);
        if(ql>tr || qr<tl) return inf;
        if(tl>=ql && tr<=qr) return tree[v];
        int tm = (tl+tr)/2;
        return min(query(2*v+1, tl, tm, ql, qr), query(2*v+2, tm+1, tr, ql, qr));
    }

    void update(int l, int r, int val) {
        if(l>r) return;
        update(0, 0, n-1, l, r, val);
    }

    // lazy propagation
    void update(int v, int tl, int tr, int ql, int qr, int val) {
        propagate(v, tl, tr);
        if(ql>tr || qr<tl) return;
        if(tl>=ql && tr<=qr) {
            lazy[v] = val;
            propagate(v, tl, tr);
            return;
        }
        int tm = (tl+tr)/2;
        update(2*v+1, tl, tm, ql, qr, val);
        update(2*v+2, tm+1, tr, ql, qr, val);
        tree[v] = min(tree[2*v+1], tree[2*v+2]);
    }
};


int n;
vector<int> a;
vector<int> b;
vector<int> val;

 
void solve() {
    cin >> n;
    a.resize(n+1);
    a[0] = inf;
    b.resize(n+1);

    val.resize(n+1);
    fill(val.begin(), val.end(), 0);
    fill(b.begin(), b.end(), 0);


    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }

    val[1]++;
    val[a[n]]++;
    b[n] = a[n];
    b[1] = 1;
    b[0] = inf;


    for(int i=n-1;i>1;i--) {
        b[i] = min(b[i+1]-1, a[i]);
        b[i] = max(b[i], 0);
        val[b[i]]++;
    }

    for(int i=1;i<=n;i++) val[i] += val[i-1];
    for(int i=0;i<=n;i++) val[i] = i - val[i];



    SegTree st(n+1);
    st.build(val);

    int ans = 0;
    if(st.query(0, n)>=0) ans++;


    for(int i=2;i<=n;i++) {
        int prev = b[i];
        b[i-1] = min(b[i-2]-1, a[i-1]);
        b[i-1] = max(b[i-1], 0);
        int cur = b[i-1];
        if(prev!=cur) {
            if(prev<cur) st.update(prev, cur-1, 1);
            else st.update(cur, prev-1, -1);
        }
        if(st.query(0, n)>=0) ans++;
    }


    cout << ans << "\n";






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