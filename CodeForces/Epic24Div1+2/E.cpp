/**
*    author:  lazyhash(yashkundu)
*    created: 30 Jun, 2024 | 21:50:43
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

const int MAXN = 5005;
const ll inf = 1e18+10;

ll a[MAXN];
vector<int> g[MAXN];

int n;
ll ans = 0;

ll del;


vector<pair<int, ll>> dfs(int v, int p = -1) {
    vector<pair<int, ll>> unsats;
    ll childsum = 0;

    for(int u: g[v]) {
        if(u==p) continue;
        auto tmpv = dfs(u, v);
        childsum += a[u];
        for(auto x: tmpv) unsats.push_back({x.first+1, x.second});
    }

    // debug(v, unsats, a[v], childsum);


    sort(unsats.rbegin(), unsats.rend());

    if(g[v].size()==1 && g[v][0]==p) {
        unsats.push_back({0, inf});
        return unsats;
    } 

    while(a[v]>childsum) {
        // debug(a[v], childsum, v);
        auto p = unsats.back();
        // debug(p);
        unsats.pop_back();
        if(p.second==inf) {
            ans += (a[v]-childsum)*(p.first);
            // debug(ans, a[v]-childsum, v);
            childsum += (a[v]-childsum);
            unsats.push_back(p);
        } else {
            del = min(p.second, a[v]-childsum);
            p.second -= del;
            childsum += del;
            ans += del*p.first;
            if(p.second) unsats.push_back(p);
        }
    }

    if(a[v]<childsum) {
        unsats.push_back({0, childsum-a[v]});
    }
    return unsats;
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=1;i<n;i++) {
        int p;
        cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    ans = 0;

    dfs(0);

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