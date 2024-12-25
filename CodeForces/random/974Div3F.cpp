/**
*    author:  lazyhash(yashkundu)
*    created: 05 Dec, 2024 | 20:20:08
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

const int MAXN = (int)2e5+10;
const ll inf = (ll)1e18+10;

vector<int> g[MAXN];

int n;
ll c;
ll a[MAXN];

int u, v;


pair<ll, ll> dfs(int v, int par) {
    vector<pair<ll, ll>> vec;
    ll summx = 0, suma = 0;
    for(int u: g[v]) {
        if(u==par) continue;
        auto p = dfs(u, v);
        summx += max(p.first, p.second);
        suma += p.first;
        vec.push_back(p);
    }

    sort(vec.begin(), vec.end(), [](const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
        return p1.second-p1.first>p2.second-p2.first;
    });

    pair<ll, ll> p = {summx, a[v]+suma};
    ll cur = 0;
    for(int i=0;i<vec.size();i++) {
        cur += vec[i].second-vec[i].first;
        p.second = max(p.second, a[v] + suma + cur - 2*(i+1)*c);
    }

    return p;
}

 
void solve() {
    cin >> n >> c;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 


    auto p = dfs(0, -1);
    ll ans = max(p.first, p.second);

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