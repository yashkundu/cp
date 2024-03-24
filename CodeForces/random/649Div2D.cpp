/**
*   author: lazyhash(yashkundu)
*   created: 21 Feb, 2024 | 22:51:33
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

const int N = 1e5+10;
vector<int> g[N];
vector<int> cycle;
int dep[N];


bool dfs(int v, int p, int d) {
    // check for a back edge to the deepest node in the current trace
    dep[v] = d;
    // debug(v, p, dep[v]);
    int cVertex = -1;
    int maxDep = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        if(dep[u] && dep[u]>maxDep) {
            cVertex = u;
            maxDep = dep[u];
        }
    }
    // debug(cVertex);
    if(cVertex!=-1) {
        cycle.push_back(cVertex);
        cycle.push_back(v);
        return true;
    }
    for(int u: g[v]) {
        if(u==p) continue;

        bool b = dfs(u, v, d+1);
        if(b) {
            cycle.push_back(v);
            return true;
        }
    }
    return false;
}


bool col[N];

void dfs2(int v, int p) {
    for(int u: g[v]) {
        if(u==p) continue;
        col[u] = 1 - col[v];
        dfs2(u, v);
    }
}

 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) g[i].clear();
    fill(dep, dep+n, 0);
    fill(col, col+n, 0);
    cycle.clear();


    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }


    dep[0] = 1;
    bool isCyclic = dfs(0, -1, 1);

    // debug(cycle);

    if(!isCyclic) {
        // color the graph
        dfs2(0, -1);
        // choose the max disjoint set
        int cnt = 0;
        for(int i=0;i<n;i++) cnt += (col[i]==0);
        bool isZero = (cnt>=(n+1)/2);
        vector<int> indSet;
        for(int i=0;i<n;i++) if((isZero && col[i]==0) || (!isZero && col[i])) indSet.push_back(i);

        cout << "1\n";
        for(int i=0;i<(k+1)/2;i++) cout << indSet[i] + 1 << " ";
        cout << "\n";
        return;
    }

    // cycle present
    int ind = 1;
    while(ind<cycle.size() && cycle[ind]!=cycle[0]) ind++;

    cycle.resize(ind);


    if(cycle.size()<=k) {
        cout << "2\n";
        cout << cycle.size() << "\n";
        for(int x: cycle) cout << x + 1 << " ";
    } else {
        cout << "1\n";
        for(int i=0,j=0;j<(k+1)/2;i+=2,j++) cout << cycle[i] + 1 << " ";
    }

    cout << "\n";









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