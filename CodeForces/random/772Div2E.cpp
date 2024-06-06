/**
*   author: lazyhash(yashkundu)
*   created: 18 Apr, 2024 | 08:46:02
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

const int N = 2e5+10;

vector<int> g[N];
vector<pair<int, pair<int, int>>> edges;
int col[N];
int vis[N] = {0};
int ans[N];

vector<int> topOrd;

int n, m;


bool dfs1(int v) {
    for(int u: g[v]) {
        if(col[u]==-1) {
            col[u] = 1 - col[v];
            if(!dfs1(u)) return false;
        } else if(col[u]==col[v]) return false;
    }
    return true;
}


bool dfs2(int v) {
    vis[v] = 1;
    for(int u: g[v]) {
        if(vis[u]==1) return false;
        if(!vis[u]) {
            vis[u] = 1;
            if(!dfs2(u)) return false;
        }
    }
    vis[v] = 2;
    topOrd.push_back(v);
    return true;
}



 
void solve() {
    cin >> n >> m;
    edges.resize(m);


    for(int i=0;i<m;i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        edges[i].first = t;
        edges[i].second.first = u;
        edges[i].second.second = v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill(col, col+n, -1);

    // bipartile coloring
    for(int i=0;i<n;i++) {
        if(col[i]!=-1) continue;
        col[i] = 0;
        if(!dfs1(i)) {
            cout << "NO\n";
            return;
        }
    }

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<m;i++) {
        if(col[edges[i].second.first]==1) swap(edges[i].second.first, edges[i].second.second);
        if(edges[i].first==1) 
            g[edges[i].second.first].push_back(edges[i].second.second);
        else
            g[edges[i].second.second].push_back(edges[i].second.first);
    }

    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        if(!dfs2(i)) {
            cout << "NO\n";
            return;
        }
    }

    reverse(topOrd.begin(), topOrd.end());

    cout << "YES\n";

    int x = 0;
    for(int i=0;i<n;i++) {
        ans[topOrd[i]] = x;
        x++;
    }

    for(int i=0;i<n;i++) {
        if(col[i]) cout << "R ";
        else cout << "L ";
        cout << ans[i] << "\n";
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