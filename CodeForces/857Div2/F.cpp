/**
*   author: lazyhash(yashkundu)
*   created: 12 Mar, 2023 | 15:10:15
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
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


const int N = 810;
const ll inf = 1e18;
vector<pair<int, int>> g[N];
vector<pair<int, int>> w;
vector<vector<ll>> dis(N, vector<ll>(N, 0));
vector<vector<ll>> dp(N, vector<ll>(2, 0));


void dijkstra(int s, vector<ll> &d) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, s);
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if(d[p.second]!=inf) continue;
        d[p.second] = p.first;
        for(auto [u, w]: g[p.second]) {
            pq.emplace(p.first+w, u);
        }
    }
}

 
void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    for(int i=0;i<n;i++) g[i].clear();
    w.clear();
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        w.emplace_back(x, i);
    }
    w.pop_back();
    w.emplace_back(1e9+100, n-1);
    sort(w.begin(), w.end());


    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
    }

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        dis[i][j] = inf;
    }

    for(int i=0;i<n;i++) {
        dijkstra(i, dis[i]);
    }


    for(int i=0;i<n;i++) {
        dp[i][0] = inf; dp[i][1] = 0;
    }

    dp[0][0] = 0; dp[0][1] = p;


    for(int i=0;i<n;i++) {
        auto [value, ind1] = w[i];
        if(dp[ind1][0]==inf) continue;
        for(int j=i+1;j<n;j++) {
            int ind2 = w[j].second;
            if(dis[ind1][ind2]==inf) continue;
            ll extra = max(0LL, dis[ind1][ind2]-dp[ind1][1]);
            ll cur_shows = (extra+value-1)/value;
            ll tot_money = (dp[ind1][1] - dis[ind1][ind2] + cur_shows*value);
            if(cur_shows+dp[ind1][0]<dp[ind2][0]) {
                dp[ind2][0] = cur_shows+dp[ind1][0];
                dp[ind2][1] = tot_money;
            } else if(cur_shows+dp[ind1][0]==dp[ind2][0]) {
                dp[ind2][1] = max(dp[ind2][1], tot_money);
            }
        }
    }

    if(dp[n-1][0]==inf) dp[n-1][0] = -1;


    cout << dp[n-1][0] << "\n";




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