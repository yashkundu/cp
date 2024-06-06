/**
*   author: lazyhash(yashkundu)
*   created: 05 Apr, 2024 | 10:00:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cstring>
 
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

const int N = 101;
const int M = 100*100 + 1;

int dp[2][N][M] = {0};
// dp[i][k][m] -> number of ways to make total m mass using exact k weights after processing elements <= i
 

int a[N];
int cnt[N];
int n;


void solve() {

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int uniqEl = 0;
    for(int i=1;i<N;i++) if(cnt[i]) uniqEl++;

    if(uniqEl<=2) {
        cout << n << "\n";
        return;
    }

    dp[0][0][0] = 1;


    for(int i=0;i<N-1;i++) {
        int ci = i&1;
        int ni = 1^ci;
        for(int k=0;k<N;k++) for(int j=0;j<M;j++) dp[ni][k][j] = 0;
        for(int k=0;k<=n;k++) {
            for(int j=0;j<M;j++) {
                if(!dp[ci][k][j]) continue;
                // choosing some of the (i+1)th element
                for(int x=0;x<=cnt[i+1];x++) {
                    // i chose x elements of the val (i+1)
                    // dp[ni][k+x][j + (i+1)*x]
                    dp[ni][k+x][j+(i+1)*x] += dp[ci][k][j];
                    dp[ni][k+x][j+(i+1)*x] = min(2, dp[ni][k+x][j+(i+1)*x]);
                }
            }
        }
    }

    int ans = 1;
    for(int i=1;i<N;i++) for(int j=1;j<=cnt[i];j++) if(dp[0][j][i*j]==1) ans = max(ans, j);

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