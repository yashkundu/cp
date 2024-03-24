/**
*   author: lazyhash(yashkundu)
*   created: 01 May, 2023 | 15:17:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
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

const int N = 2010;

vector<int> g[N];
vector<int> deg(N, 0);

int n, m;


bool dfs(int v, int p, int start, vector<int> &cycle, vector<bool> &vis) {
    vis[v] = true;
    cycle.push_back(v);
    for(int u: g[v]) {
        if(u==start && u!=p) {
            return true;
        }
        if(vis[u]) continue;
        if(dfs(u, v, start, cycle, vis))
            return true;
    }
    cycle.pop_back();
    return false;
}


vector<int> getCycle(int v) {
    vector<bool> vis(n, 0);
    vector<int> cycle;
    dfs(v, -1, v, cycle, vis);
    return cycle;
}

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();
    fill(deg.begin(), deg.begin()+n, 0);

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<bool> vis(n, 0);

    for(int i=0;i<n;i++) {
        if(deg[i]>=4) {
            auto cycle = getCycle(i);
            if(cycle.size()==0) continue;
            cout << "Yes\n";
            vector<int> goodOnes, badOnes;
            fill(vis.begin(), vis.begin()+n, 0);
            for(int v: cycle) vis[v] = 1;
            for(int u: g[i]) {
                if(vis[u]) badOnes.push_back(u);
            }
            fill(vis.begin(), vis.begin()+n, 0);
            for(int v: badOnes) vis[v] = true;
            int ind = 1;
            for(int i=2;i<cycle.size()-1;i++) if(vis[cycle[i]]) ind = i;            
            vector<int> newCycle;
            newCycle.push_back(cycle[0]);
            for(int j=ind;j<cycle.size();j++) newCycle.push_back(cycle[j]);
            fill(vis.begin(), vis.begin()+n, 0);
            for(int v: newCycle) vis[v] = 1;
            vector<pair<int, int>> ans;
            for(int u: g[i]) {
                if(!vis[u] && ans.size()<2) ans.emplace_back(i, u);
            }
            assert(ans.size()==2);
            newCycle.push_back(newCycle[0]);
            for(int j=0;j<newCycle.size()-1;j++) ans.emplace_back(newCycle[j], newCycle[j+1]);
            cout << ans.size() << "\n";
            for(auto [u, v]: ans) cout << u+1 << " " << v+1 << "\n";
            return;
        }
    }

    cout << "No\n";


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