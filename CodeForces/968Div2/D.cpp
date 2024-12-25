/**
*    author:  lazyhash(yashkundu)
*    created: 25 Aug, 2024 | 21:01:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
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

const int MAXN = int(2e5)+100;

int n, m;
map<int, bool> vis;
int a[MAXN];

int l;

vector<pair<int, int>> edges;
vector<int> vert;

vector<int> g[MAXN];


int mxval[MAXN] = {0};
int mx = 0;
int cnt = 0;

 
void solve() {
    cin >> n >> m;
    edges.clear();
    vert.clear();


    for(int j=0;j<n;j++) {
        cin >> l;
        for(int i=0;i<l;i++) {
            cin >> a[i];
            vis[a[i]] = 1;
        }
        cnt = 0;
        pair<int, int> p = {0, 0};
        for(int i=0;i<MAXN;i++) {
            if(!vis[i]) {
                cnt++;
                if(cnt==1) p.first = i;
                else if(cnt==2) {
                    p.second = i;
                    break;
                }
            }
        }
        edges.push_back(p);
        vis.clear();
    }

    mx = 0;

    for(auto p: edges) {
        g[p.first].push_back(p.second);
        mx = max(mx, p.first);
        vert.push_back(p.first);
        vert.push_back(p.second);
    }


    sort(vert.begin(), vert.end());
    vert.resize(distance(vert.begin(), unique(vert.begin(), vert.end())));
    

    for(int i=vert.size()-1;i>=0;i--) {
        int u = vert[i];
        mxval[u] = u;
        for(int v: g[u]) mxval[u] = max(mxval[u], mxval[v]);
        if(g[u].size()>1) mx = max(mx, mxval[u]);
    }

    int lgnum = vert.back();

    ll ans = 0;

    // debug(mx);
    // debug(mxval[0], mxval[1], m, lgnum);

    for(int i=0;i<=min(m, lgnum);i++) {
        ans += max(max(mxval[i], i), mx);
    }

    int del = max(0, m - lgnum);

    ans += 1LL*lgnum*del + 1LL*del*(del+1)/2;

    for(int v: vert) {
        mxval[v] = 0;
        g[v].clear();
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