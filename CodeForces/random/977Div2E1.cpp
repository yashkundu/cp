/**
*    author:  lazyhash(yashkundu)
*    created: 30 Nov, 2024 | 16:32:26
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

const ll inf = (ll)1e18+10;

const int MAXN = 405;
ll d[MAXN][MAXN];
ll latency[MAXN];
bool taken[MAXN];




int n, m, p;
int u, v;
ll w;
vector<int> houses;
 
void solve() {
    cin >> n >> m >> p;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = inf;
    for(int i=0;i<n;i++) d[i][i] = 0;

    houses.resize(p);
    for(int i=0;i<p;i++) {
        cin >> houses[i];
        houses[i]--;
    }

    for(int i=0;i<m;i++) {
        cin >> u >> v >> w;
        u--, v--;
        d[u][v] = w;
        d[v][u] = w;
    } 

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }

    for(int i=0;i<n;i++) latency[i] = inf;
    for(int i=0;i<n;i++) taken[i] = 0;

    for(int k=0;k<n;k++) {
        ll minsum = inf;
        int best = -1;
        for(int i=0;i<n;i++) {
            if(taken[i]) continue;
            ll cursum = 0;
            for(int h: houses) {
                cursum += min(latency[h], d[h][i]);
            }
            if(cursum<minsum) {
                minsum = cursum;
                best = i;
            }
        }
        taken[best] = 1;
        for(int h: houses) latency[h] = min(latency[h], d[h][best]);
        cout << minsum << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/