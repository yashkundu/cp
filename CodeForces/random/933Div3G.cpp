/**
*    author:  lazyhash(yashkundu)
*    created: 21 Jun, 2024 | 16:58:22
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

const int MAXN = 2e5+10;

vector<int> g[2*MAXN];
int dis[2*MAXN];


int n, m, b, e;
int u[MAXN], v[MAXN], c[MAXN];

void init() {
    for(int i=0;i<2*MAXN;i++) dis[i] = -1;
}


 
void solve() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> u[i] >> v[i] >> c[i];
        g[c[i]+MAXN].push_back(u[i]);
        g[u[i]].push_back(c[i]+MAXN);
        g[c[i]+MAXN].push_back(v[i]);
        g[v[i]].push_back(c[i]+MAXN);
    }

    queue<int> q;

    cin >> b >> e;

    dis[b] = 0;
    q.push(b);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y: g[x]) {
            if(dis[y]==-1) {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }

    int ans = dis[e]/2;
    
    cout << ans << "\n";

    for(int i=0;i<m;i++) {
        dis[u[i]] = dis[v[i]] = dis[c[i]+MAXN] = -1;
        g[u[i]].clear(), g[v[i]].clear(), g[c[i]+MAXN].clear();
    }
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    init();
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