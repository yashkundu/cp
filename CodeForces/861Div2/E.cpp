/**
*   author: lazyhash(yashkundu)
*   created: 02 Apr, 2023 | 16:22:50
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

ll mod = 0;

ll add(ll &a, ll b) {
    a += b;
    if(a>=mod) a -= mod;
    return a;
}

ll mul(ll &a, ll b) {
    a = (a*b)%mod;
    return (a*b)%mod;
}


const int N = 104;
const int M = 31;


ll dp[N][M][M][2] = {0};
 
void solve() {
    int n, m;

    cin >> n >> m >> mod;


    for(int i=0;i<m;i++) dp[0][0][i][0] = 1;


    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<m;k++) {
                // dp[i][j][k]
                for(int cur_el=0;cur_el<m;cur_el++) {
                    if(2*cur_el%m==k) {
                        add(dp[i][j][k][1], dp[i-1][(m+j-cur_el)%m][k][0]);
                        add(dp[i][j][k][1], dp[i-1][(m+j-cur_el)%m][k][1]);
                    } else {
                        add(dp[i][j][k][0], dp[i-1][(m+j-cur_el)%m][k][0]);
                        add(dp[i][j][k][1], dp[i-1][(m+j-cur_el)%m][k][1]);
                    }
                }
                debug(i, j, k);
                debug(dp[i][j][k][0], dp[i][j][k][1]);
            }
        } 
    }

    ll ans = 0;
    for(int i=0;i<m;i++) add(ans, dp[n][i][i][1]);
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/