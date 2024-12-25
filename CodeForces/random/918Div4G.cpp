/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jun, 2024 | 11:37:46
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>
 
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

const int MAXN = 1001;
const ll inf = 1e18+10;


ll dis[MAXN][MAXN];
int s[MAXN];
ll dp[MAXN];

vector<pair<int, int>> g[MAXN];
vector<pair<int, int>> sl;

int n, m;
int u, v, w;

void calcDis(int src, ll *dis) {
    set<pair<int, int>> st;
    
    for(int i=0;i<n;i++) dis[i] = inf;
    dis[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {
        auto [_, v] = *st.begin();
        st.erase(st.begin());
        for(auto [u, w]: g[v]) {
            if(dis[u]>dis[v]+w) {
                st.erase({dis[u], u});
                dis[u] = dis[v] + w;
                st.insert({dis[u], u});
            }
        }
    }
    // debug(dis[0], dis[1], dis[2], dis[3], dis[4]);
    return;
}


 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();
    sl.clear();


    for(int i=0;i<m;i++) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for(int i=0;i<n;i++) cin >> s[i];

    sl.push_back({s[0], 0});
    for(int i=0;i<n;i++) if(s[i]<s[0]) sl.push_back({s[i], i});

    sort(sl.rbegin(), sl.rend());
    // debug(g[1]);
    
    for(int i=0;i<n;i++) calcDis(i, dis[i]);

    // debug(sl);
    // debug(dis[1][2]);


    for(int i=0;i<sl.size();i++) dp[i] = inf;
    dp[0] = 0;

    for(int i=0;i<sl.size();i++) {
        for(int j=i+1;j<sl.size();j++) {
            dp[j] = min(dp[j], dp[i] + 1LL*sl[i].first*dis[sl[i].second][sl[j].second]);
        }
    }

    // debug(dp[3], dp[4]);


    ll ans = inf;

    for(int i=0;i<sl.size();i++) {
        ans = min(ans, dp[i] + 1LL*sl[i].first*dis[sl[i].second][n-1]);
    }

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