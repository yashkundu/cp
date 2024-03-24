/**
*   author: lazyhash(yashkundu)
*   created: 14 Feb, 2024 | 23:40:08
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

const int N = 502;
// dp[i][j] - the len of the maximum increasing sequence in [1..i] such that i is a part of the sequence and it has atmost j movable groups
int dp[N][N];
int c[N];
 
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];

    c[0] = 0;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            // select i+1
            if(c[i+1]>c[i]) {
                dp[i+1][j] = 1 + dp[i][j];
            }
            for(int k=i+2;k<=n;k++) {
                if(c[k]<c[i]) continue;
                dp[k][j+1] = 1 + dp[i][j];
            }
        }
    }

    debug(dp[1][0], dp[2][0], dp[3][0], dp[4][0], dp[5][0]);



    for(int k=1;k<=n;k++) {
        int ans = dp[n][k];
        for(int i=n-1;i>0;i--) ans = max(ans, dp[i][k-1]);
        cout << (n-ans) << " ";
    }
    cout << "\n";


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