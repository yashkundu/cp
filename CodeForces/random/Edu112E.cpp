/**
*   author: lazyhash(yashkundu)
*   created: 23 Mar, 2024 | 17:54:08
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


// min segtree with lazy updation
struct SegTree{
    vector<int> tree;
    vector<int> lazy;
    int n;
    int inf = 1e9;

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



 
const int N = 3e5+10;
const int M = 1e6+10;

int n, m;

void solve() {
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> v;
    for(int i=0;i<n;i++) {
        int l, r, w;
        cin >> l >> r >> w;
        v.push_back({w, {l, r}});
    }

    sort(v.begin(), v.end());

    int ans = 1e9;

    SegTree st(m);
    


    int p2 = 0;
    bool exit = false;
    for(int p1=0;p1<v.size();p1++) {
        while(st.query(1, m-1)==0) {
            if(p2==v.size()) {
                exit = true;
                break;
            }
            st.update(v[p2].second.first, v[p2].second.second-1, 1);
            p2++;
        }
        if(exit) break;
        ans = min(ans, v[p2-1].first-v[p1].first);
        st.update(v[p1].second.first, v[p1].second.second-1, -1);
    }

    cout << ans << "\n";



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