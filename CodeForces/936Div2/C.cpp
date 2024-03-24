/**
*   author: lazyhash(yashkundu)
*   created: 22 Mar, 2024 | 20:31:27
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
vector<int> g[N];

int n, k;







int dfs(int v, int p, int x, int &cuts) {
    int cur = 1;
    for(int u: g[v]) {
        if(u==p) continue;
        cur += dfs(u, v, x, cuts);
    }
    if(cur>=x && v) {
        cuts++;
        cur = 0;
    }
    return cur;
}



int calcMaxCuts(int x) {
    int cuts = 0;
    int left = dfs(0, -1, x, cuts);
    if(!cuts) return 0;
    if(left<x) cuts--;
    return cuts;
}



 
void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    int l = 1, r = 1e5+10;
    while(l<r) {
        int mid = (l+r+1)/2;
        int maxCuts = calcMaxCuts(mid);
        if(maxCuts>=k) l = mid;
        else r = mid - 1;
    }

    cout << l << "\n";

    
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