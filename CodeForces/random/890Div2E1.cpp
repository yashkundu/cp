/**
*    author:  lazyhash(yashkundu)
*    created: 10 Jul, 2024 | 14:17:15
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
 
const int MAXN = int(5e3)+5;

int dp[MAXN][MAXN];
vector<int> g[MAXN];

int n, p;
int m;

int calc(vector<int> &v) {
    m = v.size();
    for(int i=0;i<=m;i++) for(int j=0;j<MAXN;j++) dp[i][j] = -1;
    dp[0][0] = 0;

    for(int i=0;i<m;i++) {
        for(int j=0;j<MAXN;j++) {
            if(dp[i][j]==-1) continue;
            dp[i+1][j+v[i]] = dp[i][j];
            dp[i+1][j] = v[i] + dp[i][j];
        }
    } 

    int mx = 0;
    for(int i=0;i<MAXN;i++) {
        mx = max(mx, i*dp[m][i]);
    }

    return mx;
}

int ans = 0;

int dfs(int v, int p = -1) {
    vector<int> a;
    int cnt = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        a.push_back(dfs(u, v));
        cnt += a.back();
    }
    ans += calc(a);
    return cnt;
}


void solve() {
    cin >> n;
    
    for(int i=1;i<n;i++) {
        cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    ans = 0;
    dfs(0);

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