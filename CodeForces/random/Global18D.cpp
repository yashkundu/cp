/**
*   author: lazyhash(yashkundu)
*   created: 23 Apr, 2024 | 20:35:40
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

const int N = 2e5+10;
vector<pair<int, int>> g[N];
int par[N];
int r[N];
int edges[N][3];

int n, m;


bool dfs(int v) {
    for(auto [u, w]: g[v]) {
        if(r[u]==-1) {
            r[u] = r[v]^w;
            if(!dfs(u)) return false;
        } else if(r[u]!=r[v]^w) {
            return false;
        }
    }
    return true;
}

 
void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<n;i++) r[i] = -1;

    for(int i=0;i<n-1;i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x--, y--;
        edges[i][0] = x;
        edges[i][1] = y;
        edges[i][2] = v;
        if(v==-1) continue;
        int parity = __builtin_popcount(v)%2==0?0:1;
        g[x].emplace_back(y, parity);
        g[y].emplace_back(x, parity);
    }


    for(int i=0;i<m;i++) {
        int a, b, p;
        cin >> a >> b >> p;
        a--, b--;
        g[a].emplace_back(b, p);
        g[b].emplace_back(a, p);
    }
    

    for(int i=0;i<n;i++) {
        if(r[i]==-1) {
            r[i] = 0;
            if(!dfs(i)) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    
    for(int i=0;i<n-1;i++) {
        cout << edges[i][0]+1 << " " << edges[i][1]+1 << " ";
        if(edges[i][2]==-1) cout << (r[edges[i][0]] ^ r[edges[i][1]]);
        else cout << edges[i][2];
        cout << "\n";
    }




    

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