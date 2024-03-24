/**
*   author: lazyhash(yashkundu)
*   created: 04 Feb, 2024 | 12:08:38
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


const int N = 2e5+10;
int h[N];
pair<int, int> sortedH[N];
vector<int> g[N];
int par[N];
int rnk[N];
bool ans[N];


void initDsu(int n) {
    for(int i=0;i<n;i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int v) {
    if(par[v]==v) return v;
    return par[v] = find(par[v]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(rnk[a]<rnk[b]) swap(a, b);
    par[b] = a;
    if(rnk[a]==rnk[b]) rnk[a]++;
    return true;
}


struct Query{
    int a, b, e, ind;    
    bool operator<(const Query& q) const {
        return h[this->a] + e < h[q.a] + q.e;
    }
};


Query queryies[N];


 
void solve() {

    int n, m;
    cin >> n >> m;
    initDsu(n);
    for(int i=0;i<n;i++) g[i].clear();


    for(int i=0;i<n;i++) {
        cin >> h[i];
        sortedH[i].first = h[i];
        sortedH[i].second = i;
    }

    sort(sortedH, sortedH+n);

    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    int q;
    cin >> q;
    for(int i=0;i<q;i++) {
        int a, b, e;
        cin >> a >> b >> e;
        a--, b--;
        queryies[i] = {a, b, e, i};
    }

    sort(queryies, queryies+q);



    int ptr = 0;

    for(int i=0;i<q;i++) {
        auto q = queryies[i];
        int limH = h[q.a] + q.e;
        while(ptr<n && sortedH[ptr].first<=limH) {
            // add the vertex in dsu
            int v = sortedH[ptr].second;
            for(int u: g[v]) {
                if(h[u]<=limH) {
                    merge(u, v);
                }
            }
            ptr++;
        }
        ans[q.ind] = (find(q.a)==find(q.b));
    }


    for(int i=0;i<q;i++) {
        cout << (ans[i]?"YES":"NO") << "\n";
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