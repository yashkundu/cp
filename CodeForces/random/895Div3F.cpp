/**
*    author:  lazyhash(yashkundu)
*    created: 05 Jul, 2024 | 20:13:31
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

const int MAXN = int(1e5)+10;


vector<int> g[MAXN];
int c[MAXN];
int bad[MAXN];
int vis[MAXN];
vector<int> cycle;

int n, a;
int first;
int mnInd =-1;
int sz;

vector<int> order;


bool dfs(int v) {
    if(vis[v]==2) return false;
    if(vis[v]==1) {
        cycle.push_back(v);
        first = v;
        return true;
    }
    vis[v] = 1;
    for(int u: g[v]) {
        if(dfs(u)) {
            if(first==v) first =-1;
            if(first!=-1) cycle.push_back(v);
            vis[v] = 2;
            return true;
        }
    }
    vis[v] = 2;
    return false;
}


void dfs2(int v) {
    vis[v] = 1;
    for(int u: g[v]) {
        if(bad[v]==u) continue;
        if(vis[u]) continue;
        dfs2(u);
    }
    order.push_back(v);
}



 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    fill(bad, bad+n, -1);
    fill(vis, vis+n, 0);

    for(int i=0;i<n;i++) {
        cin >> a;
        a--;
        g[i].push_back(a);
    }

    for(int i=0;i<n;i++) {
        cin >> c[i];
    }

    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        cycle.clear();
        first = -1;
        dfs(i);
        // debug(i, cycle);
        if(cycle.size()) {
            mnInd = -1;
            sz = cycle.size();
            for(int j=0;j<sz;j++) {
                if(mnInd==-1 || c[cycle[j]]<c[cycle[mnInd]]) mnInd = j;
            }
            bad[cycle[mnInd]] = cycle[(mnInd-1+sz)%sz];
        }
    }

    // debug(bad[0], bad[1], bad[2]);

    fill(vis, vis+n, 0);
    order.clear();
    for(int i=0;i<n;i++) {
        if(!vis[i]) dfs2(i);
    }

    reverse(order.begin(), order.end());

    for(int x: order) cout << x + 1 << " ";
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