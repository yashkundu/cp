/**
*   author: lazyhash(yashkundu)
*   created: 03 Jan, 2024 | 23:30:48
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
const int M = 19;
const int B = 20;

int a[N], tin[N], tout[N];
int par[N][M] = {0};
int timer = 0;
vector<int> g[N];
vector<int> goodV[N];


int reduce(const vector<int> &basis, int x) {
    for(int i=B-1;i>=0;i--) {
        if(x&(1<<i)) {
            x ^= basis[i];
        }
    }
    return x;
}

bool addToBasis(vector<int> &basis, int x) {
    x = reduce(basis, x);
    if(!x) return false;
    for(int i=B-1;i>=0;i--) if(x&(1<<i)) {
        basis[i] = x;
        return true;
    }
    return true;
}


// calculating lca
void dfs(int v, int p) {
    par[v][0] = p;
    for(int i=1;i<M;i++) par[v][i] = par[par[v][i-1]][i-1];
    tin[v] = timer++;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
    tout[v] = timer++;
}

void dfs2(int v, int p) {
    if(v==p) goodV[v].push_back(v);
    else {
        // creating goodVertices using parents goodVertices
        vector<int> basis(B, 0);
        addToBasis(basis, a[v]);
        goodV[v].push_back(v);
        for(int u: goodV[p]) if(addToBasis(basis, a[u])) goodV[v].push_back(u);
    }
    for(int u: g[v]) {
        if(u==p) continue;
        dfs2(u, v);
    }
}


bool isAncestor(int v, int u) {
    return tin[v]<=tin[u] && tout[v]>=tout[u];
}

int lca(int v, int u) {
    if(isAncestor(v, u)) return v;
    for(int i=M-1;i>=0;i--) {
        if(!isAncestor(par[v][i], u)) v = par[v][i];
    }
    return par[v][0];
}


 
void solve() {
    int n;
    cin >> n;

    timer = 0;

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n;i++) goodV[i].clear();

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);
    dfs2(0, 0);


    int q;
    cin >> q;
    while(q--) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;
        int l = lca(x, y);
        vector<int> basis(B, 0);
        for(int v: goodV[x]) if(isAncestor(l, v)) addToBasis(basis, a[v]);
        for(int v: goodV[y]) if(isAncestor(l, v)) addToBasis(basis, a[v]);
        k = reduce(basis, k);
        if(!k) cout << "YES\n";
        else cout << "NO\n";
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