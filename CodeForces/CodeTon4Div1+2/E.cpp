/**
*   author: lazyhash(yashkundu)
*   created: 08 Apr, 2023 | 16:00:55
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
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




const int N = 2e5+10;
vector<int> par(N, 0);
vector<int> cnt(N, 0);
vector<int> a(N, 0);
vector<int> g[N];
vector<bool> vis(N, 0);


int find(int v) {
    if(v==par[v]) return v;
    return par[v] = find(par[v]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u!=v) {
        if(cnt[u]>cnt[v]) swap(u, v);
        par[u] = v;
        cnt[v] += cnt[u];
        return true;
    }
    return false;
}

void calc(int v) {
    multiset<pair<int, int>> ms;
    vis[v] = true;
    for(int u: g[v]) ms.emplace(a[u], u);    
    while(ms.size()) {
        auto it = ms.begin();
        auto [enemy, u] = *it;
        ms.erase(it);
        if(!vis[u] && enemy>cnt[find(v)]) break;
        if(!vis[u]) for(int x: g[u]) ms.emplace(a[x], x);
        vis[u] = true;
        merge(u, v);
    }
}


 
void solve() {

    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();
    fill(cnt.begin(), cnt.begin()+n, 1);
    fill(vis.begin(), vis.begin()+n, 0);
    iota(par.begin(), par.begin()+n, 0);


    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<n;i++) {
        if(!vis[i]&&!a[i]) calc(i);
    }

    if(cnt[find(0)]==n) cout << "Yes\n";
    else cout << "No\n";

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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/