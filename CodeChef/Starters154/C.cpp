/**
*    author:  lazyhash(yashkundu)
*    created: 02 Oct, 2024 | 21:05:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;

vector<int> g[MAXN];
int deg[MAXN];
int par[MAXN];
bool taken[MAXN];


int n;
int u, v;

vector<pair<pair<int, int>, int>> ops;



void dfs(int v, int p) {
    par[v] = p;
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    fill(deg, deg+n, 0);
    fill(par, par+n, 0);
    fill(taken, taken+n, 0);
    ops.clear();



    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    dfs(0, -1);

    if(n==2) {
        cout << "1\n1 2 1\n";
        return;
    }

    
    vector<int> vec;
    for(int i=1;i<n;i++) if(deg[i]==1) vec.push_back(i);



    bool even = (n%2==0);
    int cnt = n-1;
    if(even) cnt = n-3;



    for(int i=0;i<cnt;i++) {
        int u = vec.back();
        vec.pop_back();
        deg[par[u]]--;
        if(deg[par[u]]==1 && par[u]) vec.push_back(par[u]);

        if(even && i==cnt-1) ops.push_back({{par[u], u}, par[u]});
        else ops.push_back({{par[u], u}, u});
        taken[u] = u;   
    }


    if(even) {
        int a =-1, b = -1;
        for(int i=1;i<n;i++) {
            if(!taken[i]) {
                if(a==-1) a = i;
                else b = i;
            }
        }

        if(par[a]==0) swap(a, b);  
        ops.push_back({{par[a], a}, par[a]});
        ops.push_back({{par[b], b}, b});
    }


    cout << "0\n";

    for(auto p: ops) {
        cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second+1 << "\n";
    }














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