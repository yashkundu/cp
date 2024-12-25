/**
*    author:  lazyhash(yashkundu)
*    created: 09 Oct, 2024 | 21:25:08
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

const int MAXN = 2005;
const int inf = (int)1e9+10;


int dp[MAXN][MAXN][2];

int n, m;
string s, t;

void minimize(int &x, int y) {
    x = min(x, y);
}

 
void solve() {
    cin >> n >> m;
    cin >> s >> t;


    if(s[0]!=t[0]) {
        cout << "-1\n";
        return;
    }

    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) for(int k=0;k<2;k++) dp[i][j][k] = inf;

    dp[1][1][0] = 0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int k=0;k<2;k++) {
                if(dp[i][j][k]==inf) continue;
                if(i<n && j<m && s[i]==t[j]) minimize(dp[i+1][j+1][0], dp[i][j][k]);
                if(k) minimize(dp[i+1][j][1], dp[i][j][k]);
                else minimize(dp[i+1][j][1], dp[i][j][k]+1);
            }
        }
    }

    int ans = inf;
    ans = min(dp[n][m][0], dp[n][m][1]);

    if(ans==inf) ans = -1;

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