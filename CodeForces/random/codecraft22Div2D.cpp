/**
*    author:  lazyhash(yashkundu)
*    created: 12 Aug, 2024 | 23:35:19
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

const int MAXN = int(2e5)+10;
const ll inf = ll(1e18) + 10000;
int x[MAXN];
int nxt[MAXN], prv[MAXN];
ll psum[MAXN], ssum[MAXN];


int n;


struct SegTree{
  vector<ll> tree;
  int n;
  SegTree(int n) {
    this->n = n;
    tree.resize(4*n);
    fill(tree.begin(), tree.end(), -inf);
  }
  void update(int v, int tl, int tr, int ind, ll val) {
    if(ind<tl || ind>tr) return;
    if(tl==tr) {
        tree[v] = val;
        return;
    }
    int tm = (tl+tr)/2;
    update(2*v+1, tl, tm, ind, val);
    update(2*v+2, tm+1, tr, ind, val);
    tree[v] = max(tree[2*v+1], tree[2*v+2]);
  }
  void update(int ind, int val) {
    update(0, 0, n-1, ind, val);
  }
  ll query(int v, int tl, int tr, int ql, int qr) {
    if(ql>tr || qr<tl) return -inf;
    if(ql<=tl && qr>=tr) return tree[v];
    int tm = (tl+tr)/2;
    return max(query(2*v+1, tl, tm, ql, qr), query(2*v+2, tm+1, tr, ql, qr));
  }
  ll query(int ql, int qr) {
    return query(0, 0, n-1, ql, qr);
  }
};


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> x[i];


    psum[0] = x[0];
    for(int i=1;i<=n;i++) psum[i] = psum[i-1] + x[i];
    ssum[n-1] = x[n-1];
    for(int i=n-2;i>=0;i--) ssum[i] = ssum[i+1] + x[i];

    // debug(psum[0], psum[1], psum[2], psum[3]);
    // debug(ssum[0], ssum[1], ssum[2], ssum[3]);

    SegTree ptree(n), stree(n);
    for(int i=0;i<n;i++) ptree.update(i, psum[i]);
    for(int i=0;i<n;i++) stree.update(i, ssum[i]);

    vector<int> v;
    for(int i=0;i<n;i++) {
        while(!v.empty() && x[v.back()]<=x[i]) v.pop_back();
        if(v.empty()) prv[i] = -1;
        else prv[i] = v.back();
        v.push_back(i);
    }


    v.clear();
    for(int i=n-1;i>=0;i--) {
        while(!v.empty() && x[v.back()]<=x[i]) v.pop_back();
        if(v.empty()) nxt[i] = n;
        else nxt[i] = v.back();
        v.push_back(i);
    }


    for(int i=0;i<n;i++) {
        // a[i]
        if(prv[i]<i-1) {
          ll num = stree.query(prv[i]+1, i-1);
          if(num-ssum[i]>0) {
            // debug(i, prv[i], num, ssum[i]);
            cout << "NO\n";
            return;
          }
        }
        if(nxt[i]>i+1) {
          ll num = ptree.query(i+1, nxt[i]-1);
          if(num-psum[i]>0) {
            // debug(i, nxt[i], num, psum[i]);
            cout << "NO\n";
            return;
          }
        }
    }

    cout << "YES\n";




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