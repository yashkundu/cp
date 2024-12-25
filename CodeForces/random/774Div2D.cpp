/**
*    author:  lazyhash(yashkundu)
*    created: 29 Sep, 2024 | 14:28:44
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

const int MAXN = (int)2e5+10;

vector<int> g[MAXN];
pair<int, int> dp[MAXN][2];  
int wt[MAXN];

int n;
int u, v; 

pair<int, int> operator+(const pair<int, int> &p1, const pair<int, int> &p2) {
    return make_pair(p1.first + p2.first, p1.second+p2.second);
}


void dfs(int v, int p = -1) {
    dp[v][0] = {1, -(int)g[v].size()};
    dp[v][1] = {0, 0};
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        dp[v][0] = dp[v][0] + dp[u][1];
        dp[v][1] = dp[v][1] + max(dp[u][0], dp[u][1]);
    }
}


void dfs2(int v, int p, int cur) {
    if(cur) wt[v] = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        if(!cur) dfs2(u, v, 1);
        else dfs2(u, v, dp[u][1]>dp[u][0]);
    }
}



void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    fill(wt, wt+n, 0);

    for(int i=0;i<n-1;i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    if(n==2) {
        cout << "2 2\n1 1\n";
        return;
    }

    dfs(0, -1);

    int cur = dp[0][1]>dp[0][0];

    dfs2(0, -1, cur);

    for(int i=0;i<n;i++) if(!wt[i]) wt[i] = (int)g[i].size();

    cout << dp[0][cur].first << " " << -dp[0][cur].second + n - dp[0][cur].first << "\n";
    for(int i=0;i<n;i++) cout << wt[i] << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/