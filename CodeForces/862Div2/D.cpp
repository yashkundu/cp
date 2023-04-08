/**
*   author: lazyhash(yashkundu)
*   created: 03 Apr, 2023 | 00:09:20
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

const int N = 1e5+10;
vector<int> g[N];


void dfs(int v, int p, vector<int> &dis) {
    for(int u: g[v]) {
        if(u==p) continue;
        dis[u] = 1 + dis[v];
        dfs(u, v, dis);
    }
}
 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 

    vector<int> dis(n);
    dis[0] = 0;
    dfs(0, -1, dis);
    int d1 = 0, x = 0;
    for(int i=0;i<n-1;i++) {
        if(dis[i]>x) {
            x = dis[i];
            d1 = i;
        }
    }

    dis[d1] = 0;
    dfs(d1, -1, dis);
    debug(dis);
    int d2 = 0; x = dis[0];
    for(int i=0;i<n;i++) {
        if(dis[i]>x) {
            x = dis[i];
            d2 = i;
        }
    }
    // d1-d2 - diameter
    vector<int> dis1(n, 0), dis2(n, 0);
    dfs(d1, -1, dis1);
    dfs(d2, -1, dis2);

    debug(d1, d2);

    vector<int> eccs;

    for(int i=0;i<n;i++) {
        eccs.push_back(max(dis1[i], dis2[i]));
    }

    sort(eccs.begin(), eccs.end());

    debug(eccs);

    int ans = n;


    int j = 0;
    for(int i=1;i<=n;i++) {
        cout << min(1+j, n) << " ";
        while(j<n && eccs[j]<=i) j++;
    }

    cout << "\n";





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