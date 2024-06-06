/**
*   author: lazyhash(yashkundu)
*   created: 14 Apr, 2024 | 13:05:32
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

const int N = 1e5+10;
int a[N];

const ll inf = 1e18+10;

vector<pair<int, pair<int, int>>> g[N];


 
void solve() {
    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=0;i<m;i++) {
        int e, t, p;
        cin >> e >> t >> p;
        e--;
        g[e].push_back({i+1, {t, p}});
    }


    vector<vector<ll>> dp;
    vector<vector<int>> lastOp;


    vector<int> ops;
    ll timeTillNow = 0;

    for(int i=0;i<n;i++) {
        if(g[i].empty()) {
            cout << "-1\n";
            return;
        }
        int sz = g[i].size();
        dp.resize(sz+1);
        lastOp.resize(sz+1);
        for(int j=0;j<=sz;j++) {
            dp[j].resize(200);
            lastOp[j].resize(200);
            fill(dp[j].begin(), dp[j].end(), inf);
            fill(lastOp[j].begin(), lastOp[j].end(), -1);
        }
        dp[0][0] = 0;

        for(int j=0;j<sz;j++) {
            for(int k=0;k<200;k++) {
                if(dp[j][k]==inf) continue;
                // take a[j]
                // d[j+1][k+p[j]]
                if(k<100 && dp[j][k] + g[i][j].second.first < dp[j+1][k+g[i][j].second.second]) {
                    dp[j+1][k+g[i][j].second.second] = dp[j][k] + g[i][j].second.first;
                    lastOp[j+1][k+g[i][j].second.second] = j;
                }
                // leave a[j]
                dp[j+1][k] = min(dp[j+1][k], dp[j][k]);
            }
        }

        ll mnTime = inf;
        int mnTimePer = -1;
        for(int j=100;j<200;j++) {
            if(dp[sz][j]<mnTime) {
                mnTime = dp[sz][j];
                mnTimePer = j;
            }
        }

        if(mnTimePer==-1 || timeTillNow+mnTime>a[i]) {
            cout << "-1\n";
            return;
        }
        timeTillNow += mnTime;

        int ind = sz;
        int per = mnTimePer;
        while(per!=0) {
            int j = lastOp[ind][per];
            if(j==-1) {
                ind--;
                continue;
            }
            ops.push_back(g[i][j].first);
            ind = j;
            per -= g[i][j].second.second;
        }
    }

    cout << ops.size() << "\n";
    for(int op: ops) cout << op << " ";
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