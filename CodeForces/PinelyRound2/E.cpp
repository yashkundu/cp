/**
*   author: lazyhash(yashkundu)
*   created: 16 Sep, 2023 | 22:44:16
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <numeric>
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
vector<int> g[N], gR[N];
ll t[N];
int inDeg[N], inDegK[N];
bool vis[N];


void dfs(int v, int k, ll & maxT) {
    t[v] += k;
    vis[v] = 1;
    maxT = max(maxT, t[v]);
    for(int u: g[v]) {
        if(vis[u]) continue;
        if(t[u]<t[v]) dfs(u, k, maxT);
    }
}

 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) g[i].clear(), gR[i].clear();
    fill(inDeg, inDeg+n, 0);
    fill(inDegK, inDegK+n, 0);
    fill(t, t+n, 0);

    vector<ll> h(n);
    
    for(int i=0;i<n;i++) cin >> h[i];
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        inDeg[b]++;
        inDegK[b]++;
        g[a].push_back(b);
        gR[b].push_back(a);
    }

    

    queue<int> q;
    for(int i=0;i<n;i++) if(!inDeg[i]) q.push(i);

    auto f = [k](ll x, ll y) {
        if(y>x) return y;
        ll del = x-y;
        ll z = y + (del+k-1)/k*k;
        return z;
    };

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        ll maxT = 0;
        for(int u: gR[v]) maxT = max(maxT, t[u]);
        t[v] = f(maxT, h[v]);
        for(int u: g[v]) {
            inDeg[u]--;
            if(!inDeg[u]) q.push(u);
        }
    }

    vector<int> orderedV(n);
    iota(orderedV.begin(), orderedV.end(), 0);

    sort(orderedV.begin(), orderedV.end(), [h](int i, int j) {
        return h[i]<h[j];
    });

    fill(vis, vis+n, 0);
    ll maxT = 0;
    for(int i=0;i<n;i++) maxT = max(maxT, t[i]);
    ll ans = maxT-0;


    vector<int> startingV;
    for(int v: orderedV) if(!inDegK[v]) startingV.push_back(v);


    for(int i=0;i<startingV.size();) {
        int j = i;
        while(j<startingV.size() && h[startingV[j]]==h[startingV[i]]) j++;
        ans = min(ans, maxT-h[startingV[i]]);
        for(int p=i;p<j;p++) if(!vis[startingV[p]]) dfs(startingV[p], k, maxT);
        i = j;
    }
    

    cout << ans << "\n";








    // starting at time = 0;



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