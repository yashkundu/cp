/**
*   author: lazyhash(yashkundu)
*   created: 29 Jan, 2024 | 23:00:32
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


const int N = 3003;
// pref[i][j] - the max number of consecutive ones that can be formed ending at i by doing j operations
int pref[N][N], suf[N][N];
int n, k;


// dp[l]  - the maximum l1, which can be obtained if we have l as the l0
int dp[N];
int ones[N];

 
void solve() {
    cin >> n >> k;
    string s;
    cin >> s;

    for(int i=0;i<n+2;i++) for(int j=0;j<=n;j++) pref[i][j] = suf[i][j] = 0;
    fill(ones, ones+n+1, 0);

    for(int i=0;i<n;i++) {
        if(s[i]=='1') ones[i+1]++;
        ones[i+1] += ones[i];
    }



    for(int i=1;i<=n;i++) {
        for(int j=0;j<=i;j++) {
            if(s[i-1]=='1') pref[i][j] = pref[i-1][j] + 1;
            else pref[i][j] = (j>0?pref[i-1][j-1]+1:0);
        }
    }

    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<=n-i;j++) {
            if(s[i]=='1') suf[i][j] = suf[i+1][j]+1;
            else suf[i][j] = (j>0?suf[i+1][j-1]+1:0);
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            pref[i][j] = max(pref[i-1][j], pref[i][j]);
            if(j>0) pref[i][j] = max(pref[i][j-1], pref[i][j]);
        }
    }

    for(int i=n-1;i>=0;i--) {
        for(int j=0;j>=n;j++) {
            suf[i][j] = max(suf[i+1][j], suf[i][j]);
            if(j>0) suf[i][j] = max(suf[i][j-1], suf[i][j]);
        }
    }

    // k - max number of changes which can be done

    fill(dp, dp+n+1, -1);
    dp[0] = pref[n][k];
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=n;j++) {
            // [i, j]
            // ones[j] - ones[i-1]
            int totOnes = ones[j] - ones[i];
            if(totOnes>k) continue;
            int leftOnes = k - totOnes;
            dp[j-i] = max(dp[j-i], max(pref[i][leftOnes], suf[j][leftOnes]));
        }
    }


    for(int c=1;c<=n;c++) {
        ll ans = 0;
        for(int l0=0;l0<=n;l0++) {
            if(dp[l0]==-1) break;
            ans = max(ans, 1LL*c*l0 + dp[l0]);
        }
        cout << ans << " ";
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