/**
*    author:  lazyhash(yashkundu)
*    created: 20 Oct, 2024 | 15:49:20
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

const ll inf = (ll)1e18+100;


struct SegTree{
    vector<ll> tree;
    int n;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, inf);
    }

    ll query(int l, int r) {
        if(l>r) return inf;
        return query(0, 0, n-1, l, r);
    }

    ll query(int v, int tl, int tr, int ql, int qr) {
        if(ql>tr || qr<tl) return inf;
        if(tl>=ql && tr<=qr) return tree[v];
        int tm = (tl+tr)/2;
        return min(query(2*v+1, tl, tm, ql, qr), query(2*v+2, tm+1, tr, ql, qr));
    }

    void update(int ind, ll val) {
        update(0, 0, n-1, ind, val);
    }

    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            tree[v] = min(tree[v], new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2+1, tl, tm, pos, new_val);
            else
                update(v*2+2, tm+1, tr, pos, new_val);
            tree[v] = min(tree[v*2+1], tree[v*2+2]);
        }
    }
};

int n;
vector<ll> a;
vector<int> b;

 
void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);


    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        cin >> b[i];
        b[i]--;
    }

    SegTree st(n);

    st.update(0, 0);

    ll ans = 0;
    ll cur = 0;


    for(int i=0;i<n;i++) {
        cur += a[i];
        ll val = st.query(i, n-1);
        // debug(i, cur, val, b[i]);
        ans = max(ans, cur - val);
        st.update(b[i], val + a[i]);
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