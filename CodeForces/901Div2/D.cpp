/**
*   author: lazyhash(yashkundu)
*   created: 03 Oct, 2023 | 09:37:15
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

ll inf = 1e18+100;
 
void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(n+1, 0);
    // a > n won't have any affect on the answer because mex <= n
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a<=n) {
            cnt[a]++;
        }
    }
    vector<ll> dp(n+2, 0);
    // we just want to transition to mex=0
    // dp[i] - the minimum value of m, to make mex=i

    for(int i=0;i<=n;i++) {
        if(cnt[i]) {
            dp[i] = inf;
        } else {
            for(int j=i+1;j<=n;j++) dp[j] = 0;
            break;
        }
    }


    dp[n+1] = 0;
    for(int i=n+1;i>=0;i--) {
        // current mex=i
        for(int j=i-1;j>=0;j--) {
            // transitioning to mex=j
            // way to do it is to remove cnt[j] elements, which will add i*cnt[j] to the total sum
            if(!cnt[j]) continue;
            dp[j] = min(dp[j], dp[i] + 1LL*(cnt[j]-1)*i + j);
        }
    }

    cout << dp[0] << "\n";

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