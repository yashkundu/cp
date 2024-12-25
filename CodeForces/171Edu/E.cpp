/**
*    author:  lazyhash(yashkundu)
*    created: 04 Nov, 2024 | 08:47:22
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
 
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


struct FlowEdge{
    int v, u, cap, flow=0;
    FlowEdge(int v, int u, int cap): v(v), u(u), cap(cap) {}
};


struct Dinic{
    const int INF = (int)1e9+10;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;


    Dinic(int n, int s, int t): n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m+1);
        m += 2;
    }

    bool bfs() {
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int id: adj[v]) {
                if(edges[id].cap == edges[id].flow) continue;
                if(level[edges[id].u]!=-1) continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t]!=-1;
    }

    int dfs(int v, int pushed) {
        if(pushed==0) return 0;
        if(v==t) return pushed;
        for(int& cid = ptr[v];cid<(int)adj[v].size();cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if(level[u]!=level[v]+1) continue;
            int cur = dfs(u, min(pushed, edges[id].cap-edges[id].flow));
            if(cur==0) continue;
            edges[id].flow += cur;
            edges[id^1].flow -= cur;
            return cur;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while(true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs()) {
                break;
            }
            fill(ptr.begin(), ptr.end(),0);
            while(int pushed = dfs(s, INF)) f += pushed;
        }
        return f;
    }
};


const int B = 60;

int n;
vector<ll> a;

 
void solve() {
    cin >> n;
    a.resize(n);

    for(int i=0;i<n;i++) cin >> a[i];

    int s = 0, t = n+B+1;

    Dinic dn(t+1, s, t);


    for(int i=0;i<n;i++) {
        dn.add_edge(s, i+1, 1);
        for(int j=0;j<B;j++) {
            if((a[i]>>j)&1) dn.add_edge(i+1, n+j+1, 1);
        }
    }

    for(int j=0;j<B;j++) dn.add_edge(n+j+1, t, 1);

    int mm = dn.flow();

    int ans = n - mm;

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