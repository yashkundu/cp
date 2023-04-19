/**
*   author: lazyhash(yashkundu)
*   created: 09 Apr, 2023 | 15:41:34
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
 
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

struct Cmp{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
        if(p1.first==p2.first) return p1.second<p2.second;
        return p1.first>p2.second;
    }
};

using st = set<pair<int, int>, Cmp>;


const int N = 1e5+10;
vector<ll> a(N, 0);
vector<int> g[N];
// importance of a subtree
vector<ll> imp(N, 0);
// size of a subtree
vector<int> sz(N, 0), par(N, 0);
st son[N];

void dfs(int v, int p) {
    par[v] = p;
    imp[v] = a[v];
    sz[v] = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        sz[v] += sz[u];
        imp[v] += imp[u];
    }
    for(int u: g[v]) {
        if(u==p) continue;
        son[v].emplace(sz[u], u);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);
   


    while(m--) {
        int t, x;
        cin >> t >> x;
        x--;
        if(t==1) {
            cout << imp[x] << "\n";
        } else {
            if(son[x].empty()) continue;
            auto it = son[x].begin();
            auto [sizeChild, child] = *it; 
            son[x].erase(it);
            son[par[x]].erase({sz[x], x});
            sz[x] -= sz[child];
            imp[x] -= imp[child];
            sz[child] += sz[x];
            imp[child] += imp[x];
            par[child] = par[x];
            par[x] = child; 
            son[child].emplace(sz[x], x);
            son[par[child]].emplace(sz[child], child);
        }
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