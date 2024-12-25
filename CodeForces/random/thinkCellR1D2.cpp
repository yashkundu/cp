/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jun, 2024 | 16:36:05
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


const int MAXN = 1e6+10;

ll dp[MAXN][2][2];

int n;
string s;
 
void solve() {
    cin >> n;
    cin >> s;

    for(int i=0;i<=n;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) dp[i][j][k] = 0;



    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            for(int k=0;k<2;k++) {
                if(!dp[i][j][k]) continue;
                if(s[i]=='0') {
                    dp[i+1][k][0] += dp[i][j][k];
                    
                } else {
                    if(j || k) dp[i+1][k][0] += dp[i][j][k];
                    else dp[i+1][k][1] += dp[i][j][k];
                }
            }
        }
        if(s[i]=='0') dp[i+1][0][0]++;
        else dp[i+1][0][1]++;
    }

    // debug(dp[1][0][1], dp[2][0][0], dp[2][1][0], dp[3][0][1], dp[3][0][0]);

    ll ans = 0;
    for(int i=1;i<=n;i++) ans += dp[i][1][0]*(n-i+1) + dp[i][0][1];

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