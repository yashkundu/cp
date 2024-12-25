/**
*    author:  lazyhash(yashkundu)
*    created: 25 Nov, 2024 | 21:42:03
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

const int MAXN = (int)2e5+10;
const int LG = 19;
const int inf = (int)5e5;

vector<int> g[MAXN];

int dep[MAXN], d[MAXN];
int val[MAXN][LG];
int par[MAXN][LG];

int n, q;
int u, v;
int k;


void dfs1(int v, int p=-1) {
    dep[v] = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        d[u] = 1 + d[v];
        dfs1(u, v);
        dep[v] = max(dep[v], 1+dep[u]);
    }
} 

void dfs2(int v, int p=-1) {
    par[v][0] = max(p, 0);
    for(int j=1;j<LG;j++) {
        par[v][j] = par[par[v][j-1]][j-1];
        val[v][j] = max(val[v][j-1], val[par[v][j-1]][j-1]);
    }
    multiset<int> ms;
    for(int u: g[v]) {
        if(u==p) continue;
        ms.insert(dep[u]);
    }
    for(int u: g[v]) {
        if(u==p) continue;
        ms.extract(dep[u]);
        if(ms.empty()) val[u][0] = -d[v];
        else val[u][0] = *(ms.rbegin()) + 1 - d[v];
        ms.insert(dep[u]);
    }
    for(int u: g[v]) {
        if(u==p) continue;
        dfs2(u, v);
    }
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    val[0][0] = 0;
    d[0] = 0;

    for(int i=0;i<n-1;i++) {
        cin >> u  >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    dfs1(0);
    dfs2(0);

    cin >> q;

    for(int i=0;i<q;i++) {
        cin >> v >> k;
        v--;
        int x = v;
        int ans = dep[v];
        for(int j=0;j<LG;j++) {
            if((k>>j)&1) {
                ans = max(ans, val[x][j]+d[v]);
                x = par[x][j];
            }
        }
        cout << ans << " ";
    }

    cout << "\n";



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