/**
*   author: lazyhash(yashkundu)
*   created: 16 Mar, 2024 | 13:47:37
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+10;
pair<pair<int, int>, int> edges[N];
bool hasEvenComp[30][N];

vector<pair<int, int>> g[N];


struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int n) {
        par.resize(n);
        rank.resize(n, 0);
        iota(par.begin(), par.end(), 0);

    }

    UnionFind() {}

    int find(int v) {
        if(par[v]==v) return v;
        return par[v] = find(par[v]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u==v) return false;
        if(rank[u]>rank[v]) swap(u, v);
        par[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
        return true;
    }
} dsu1[30], dsu2[30];
 
void solve() {
    int n, m;
    cin >> n >> m;

    for(int j=0;j<30;j++) for(int i=0;i<n;i++) hasEvenComp[j][i] = false;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges[i] = {{u, v}, w};
    }

    // precalculate
    // for mex-0
    for(int bit=0;bit<30;bit++) {
        dsu1[bit] = UnionFind(n);
        int k = (1<<bit);
        for (auto e: edges) {
            if(e.second&k) {
                dsu1[bit].merge(e.first.first, e.first.second);
            }
        }
    }
    // for mex-1
    for(int bit=1;bit<30;bit++) {
        dsu2[bit] = UnionFind(n);
        int k = (1<<bit);
        for (auto e: edges) {
            if((e.second&1) && (e.second&k)) {
                dsu2[bit].merge(e.first.first, e.first.second);
            }
        }
    }

    // calculating hasEvenComp
    for(int bit=1;bit<30;bit++) {
        for(int i=0;i<n;i++) {
            bool hasEvenEdge = 0;
            for(auto [u, w]: g[i]) {
                if(w%2==0) hasEvenEdge = 1;
            }
            if(hasEvenEdge) {
                hasEvenComp[bit][dsu2[bit].find(i)] = 1;
            }
        }
    }


    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int mex = 2;
        for(int bit=0;bit<30;bit++) {
            if(dsu1[bit].find(a)==dsu1[bit].find(b)) {
                mex = 0;
                break;
            }
        }
        if(mex==0) {
            cout << mex << "\n";
            continue;
        }
        for(int bit=1;bit<30;bit++) {
            if(hasEvenComp[bit][dsu2[bit].find(a)]) {
                mex = 1;
                break;
            }
        }
        cout << mex << "\n";
    }


    

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