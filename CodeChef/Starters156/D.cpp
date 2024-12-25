/**
*    author:  lazyhash(yashkundu)
*    created: 19 Oct, 2024 | 18:23:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)2e5+10;

vector<int> g[MAXN];
int n;
int u, v;

vector<int> ops;
int a, b;



void dfs(int v, int p = -1) {
    if(v!=a && v!=b) cout << v+1 << " ";
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
}



 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    a = -1; b = -1;

    for(int i=0;i<n && a==-1;i++) {
        if(g[i].size()<2) continue;
        for(int j: g[i]) {
            if(g[j].size()<2) continue;
            a = j;
            b = i;
            break;
        }
    }

    if(a==-1) {
        cout << "-1\n";
        return;
    }

    for(int i: g[b]) {
        if(i!=a) {
            a = i;
            break;
        }
    }

    cout << b+1 << " " << a+1 << " ";
    dfs(a);

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