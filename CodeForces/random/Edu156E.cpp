/**
*   author: lazyhash(yashkundu)
*   created: 10 Jan, 2024 | 13:07:01
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
 
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
 
const int inf = 1e9+100;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a.begin(), a.end());

    auto minNumOfPs = [](int difficulty, int minTolerance) {
        return (difficulty+minTolerance-1)/minTolerance;
    };

    vector<vector<pair<int, int>>> nxt(n, vector<pair<int, int>>(m));

    for(int j=0;j<m;j++) {
        int diff = b[j];
        pair<int, int> mnUntillNow = {inf, 0};
        for(int i=n-1;i>=0;i--) {
            int numPs = minNumOfPs(diff, a[i].first);
            if(i+numPs<=n) {
                pair<int, int> p = {i+numPs, i};
                mnUntillNow = min(mnUntillNow, p);
            }
            nxt[i][j] = mnUntillNow;
        }
    }


    vector<int> dp(1<<m, inf);
    dp[0] = 0;

    for(int mask=0;mask<(1<<m);mask++) {
        // iterating over which group to choose next
        if(dp[mask]>=n) continue;
        int k = 1;
        int x = mask;
        for(int j=0;j<m;j++) {
            if(!(x&1)) {
                // can be chosen
                dp[mask+k] = min(nxt[dp[mask]][j].first, dp[mask+k]);
            }
            x = x>>1;
            k = k<<1;
        }
    }



    if(dp[(1<<m)-1]>n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int mask = (1<<m) - 1;
    vector<pair<int, int>> ans(m);

    while(mask) {
        for(int j=0;j<m;j++) {
            if(((mask>>j)&1) && dp[mask^(1<<j)]<n && nxt[dp[mask^(1<<j)]][j].first<=n && nxt[dp[mask^(1<<j)]][j].first==dp[mask]) {
                ans[j] = nxt[dp[mask^(1<<j)]][j];
                mask = mask^(1<<j);
            }
        }
    }


    for(int j=0;j<m;j++) {
        cout << ans[j].first - ans[j].second << " ";
        for(int i=ans[j].second;i<ans[j].first;i++) cout << a[i].second << " ";
        cout << "\n";
    }


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