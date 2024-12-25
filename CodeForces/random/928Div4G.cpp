/**
*    author:  lazyhash(yashkundu)
*    created: 25 Jun, 2024 | 18:01:02
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

const int MAXN = 1e5+5;
const int inf = 1e6+10;

int dp[MAXN][3];
vector<int> g[MAXN];
string s;

int n;
int a;

// 0 - C, 1 - P, 2 - S
 

void dfs(int v, int p) {
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
    if(s[v]=='P' || s[v]=='C') {
        dp[v][1] = 0;
        for(int u: g[v]) {
            if(u==p) continue;
            dp[v][1] += min(dp[u][2]+1, min(dp[u][0], dp[u][1]));
        }
    }
    if(s[v]=='S' || s[v]=='C') {
        dp[v][2] = 0;
        for(int u: g[v]) {
            if(u==p) continue;
            dp[v][2] += min(dp[u][1]+1, min(dp[u][0], dp[u][2]));
        }
    }
    if(s[v]=='C') {
        dp[v][0] = 0;
        for(int u: g[v]) {
            if(u==p) continue;
            dp[v][0] += min(dp[u][0], min(dp[u][1]+1, dp[u][2]+1));
        }
    }
}


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n;i++) for(int j=0;j<3;j++) dp[i][j] = inf;


    for(int i=1;i<n;i++) {
        int a;
        cin >> a;
        a--;
        g[i].push_back(a);
        g[a].push_back(i);
    }

    cin >> s;


    dfs(0, -1);
    // debug(dp[1][0], dp[1][1], dp[1][2], dp[2][0], dp[2][1], dp[2][2]);
    // debug(dp[0][0], dp[0][1], dp[0][2]);

    int ans = min(dp[0][0], min(dp[0][1], dp[0][2]));

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