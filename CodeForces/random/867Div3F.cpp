/**
*    author:  lazyhash(yashkundu)
*    created: 16 Jul, 2024 | 14:09:09
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

vector<int> g[MAXN];
int dep[MAXN];

int n;
ll k, c;

int u, v;


void dfs0(int v, int p = -1) {
    int d = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs0(u, v);
        d = max(d, dep[u]);
    }
    dep[v] = d + 1;
}

ll ans = 0;

void dfs(int v, int p = -1, ll cost=0) {
    ans = max(ans, k*(dep[v]-1) - cost);
    int d1=0, d2 = 0;
    for(int u: g[v]) {
        int d = dep[u];
        if(d>=d1) {
            d2 = d1;
            d1 =d ;
        } else if(d>d2) d2 = d;
    }
    for(int u: g[v]) {
        if(u==p) continue;
        int or_v = dep[v];
        int or_u = dep[u];
        dep[v] = (dep[u]==d1?d2+1:d1+1);
        dep[u] = max(dep[u], dep[v]+1);
        dfs(u, v, cost +c);
        dep[v] = or_v;
        dep[u] = or_u;
    }
}



 
void solve() {
    cin >> n >> k >> c;
    for(int i=0;i<n;i++) g[i].clear();


    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs0(0);

    ans = 0;
    dfs(0);

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