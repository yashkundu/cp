/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jul, 2024 | 16:09:33
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

const int MAXN = int(2e5)+10;
const int LG = 20;

int n, u, v;
vector<int> g[MAXN];

int par[MAXN][LG] = {0};

int dep[MAXN] = {0};
int tin[MAXN], tout[MAXN];
bool taken[MAXN] = {0};
int timer = 0;

bool good;

int lca = -1;


void dfs(int v, int p = -1) {
    par[v][0] = max(0, p);
    for(int j=1;j<LG;j++) par[v][j] = par[par[v][j-1]][j-1];
    tin[v] = timer++;
    for(int u: g[v]) {
        if(u==p) continue;
        dep[u] = 1 + dep[v];
        dfs(u, v);
    }
    tout[v] = timer++;
}

bool isanc(int v, int u) {
    return tin[v]<tin[u] && tout[v]>tout[u];
}

int getlca(int v, int u) {
    if(isanc(v, u)) return v;
    for(int j=LG-1;j>=0;j--) {
        if(!isanc(par[v][j], u)) v = par[v][j];
    }
    return par[v][0];
}


int q, k, p;
vector<pair<int, int>> vec;


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();


    for(int i=0;i<n-1;i++) {
        cin >> u >> v, u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }


    timer = 0;
    dfs(0);

    cin >> q;
    while(q--) {
        cin >> k;
        vec.resize(k);
        for(int i=0;i<k;i++) {
            cin >> p, p--;
            vec[i] = {dep[p], p};
        }
        sort(vec.begin(), vec.end());
        fill(taken, taken+k, 0);
        good = true;
        for(int num=0;num<2;num++) {
            int last = -1;
            for(int i=k-1;i>=0;i--) if(!taken[i]) {
                last = i;
                break;
            }
            if(last==-1) continue;
            if(num) lca = getlca(vec.back().second, vec[last].second);
            taken[last] = 1;
            for(int i=last-1;i>=0;i--) {
                if(isanc(vec[i].second, vec[last].second)) {
                    if(taken[i] && vec[i].second!=lca) good = false;
                    taken[i]= 1;
                    last = i;
                }
            }
        }

        for(int i=0;i<k;i++) if(!taken[i]) good = false;
        if(!good) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/