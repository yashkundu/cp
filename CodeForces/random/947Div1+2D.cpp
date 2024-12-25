/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jun, 2024 | 16:15:30
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

const int N = 2e5+10;
int dep[N], par[N];
vector<int> g[N];

void dfs(int v, int p) {
    par[v] = p;
    for(int u: g[v]) {
        if(u==p) continue;
        dep[u] = 1 + dep[v];
        dfs(u, v);
    }
}


int n, a, b;
int x, y;

 
void solve() {
    cin >> n;
    cin >> a >> b;
    a--; b--;

    for(int i=0;i<n;i++) g[i].clear();


    for(int i=0;i<n-1;i++) {
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dep[a] = 0;
    dfs(a, -1);

    int del = (dep[b]+1)/2;

    int cur = b;
    for(int i=0;i<del;i++) cur = par[cur];

    dep[cur] = 0;
    dfs(cur, -1);


    int mx = 0;
    for(int i=0;i<n;i++) mx = max(mx, dep[i]);

    int ans = del + 2*(n-1) - mx;

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