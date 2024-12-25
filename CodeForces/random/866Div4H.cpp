/**
*    author:  lazyhash(yashkundu)
*    created: 11 Jul, 2024 | 12:42:22
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

vector<pair<int, int>> g[MAXN];
ll dis[MAXN];
bool vis[MAXN];

int n, m, a, b, d;
vector<pair<int, pair<int, int>>> conditions;

void dfs(int v) {
    vis[v] = 1;
    for(auto [u, w]: g[v]) {
        if(vis[u]) continue;
        dis[u] = dis[v] + w;
        dfs(u);
    }
}


 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();
    fill(vis, vis+n, 0);

    conditions.clear();
    for(int i=0;i<m;i++) {
        cin >> a >> b >> d;
        a--, b--;
        conditions.push_back({d, {a, b}});
        g[b].push_back({a, d});
        g[a].push_back({b, -d});
    }

    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dis[i] = 0;
            dfs(i);
        }
    }

    for(auto p: conditions) {
        if(dis[p.second.first]-dis[p.second.second]!=p.first) {
            cout << "NO\n";
            return;
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