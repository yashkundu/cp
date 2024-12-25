/**
*    author:  lazyhash(yashkundu)
*    created: 20 Jul, 2024 | 00:35:36
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

const int inf = int(1e9) + 10;

int n, u, v;
int a, b;
int d;
int m1, m2;

bool spec[MAXN][2];

vector<int> g[MAXN];


pair<int, int> dfs1(int v, int p = -1) {
    int d1 = -inf, d2 = -inf;
    for(int u: g[v]) {
        if(u==p) continue;
        auto p = dfs1(u, v);
        d1 = max(d1, p.first+1);
        d2 = max(d2, p.second+1);
    }
    if(spec[v][0]) d1 = max(d1, 0);
    if(spec[v][1]) d2 = max(d2, 0);
    if(d1>=d) spec[v][1] = 1;
    if(d2>=d) spec[v][0] = 1;
    return {d1, d2};
}


int dfs2(int v, int ind, int p = -1) {
    int cnt = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        cnt += dfs2(u, ind, v);
    }
    if(cnt) cnt++;
    if(spec[v][ind]) cnt = max(cnt, 1);
    return cnt;
}

 
void solve() {
    cin >> n >> d;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n;i++) for(int j=0;j<2;j++) spec[i][j] = 0;

    for(int i=0;i<n-1;i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    cin >> m1;
    for(int i=0;i<m1;i++) {
        cin >> a, a--;
        spec[a][0] = 1;
    }
    spec[0][0] = 1;

    cin >> m2;
    for(int i=0;i<m2;i++) {
        cin >> b, b--;
        spec[b][1] = 1;
    }
    spec[0][1] = 1;

    dfs1(0);

    int ans = 2*(dfs2(0, 0) + dfs2(0, 1) - 2);
    cout << ans << "\n";


    
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/