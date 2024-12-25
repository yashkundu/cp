/**
*    author:  lazyhash(yashkundu)
*    created: 30 Oct, 2024 | 20:51:42
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1005;

vector<pair<int, int>> g[MAXN];
bool taken[MAXN];
int ans[MAXN];

vector<vector<int>> ops;

int n;
int u, v;

void dfs(int v, int p, bool b, vector<int> &vec) {
    bool done = false;
    for(auto [u, e]: g[v]) {
        if(u==p) continue;
        if(!b && !done && !taken[e]) {
            vec.push_back(v);
            vec.push_back(u);
            taken[e] = 1;
            done = true;
            dfs(u, v, true, vec);
        } else dfs(u, v, false, vec);
    }
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    fill(taken, taken+n, 0);


    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    ops.clear();


    for(int i=0;i<n-1;i++) {
        vector<int> v;
        dfs(0, -1, 0, v);
        if(v.empty()) break;
        ops.push_back(v);
    }

    cout << ops.size() << "\n";

    for(auto &v: ops) {
        fill(ans, ans+n, 0);
        int cntr = 1;

        for(int i=0;i<v.size();i+=2) {
            ans[v[i]] = ans[v[i+1]] = cntr++;
        }


        for(int i=0;i<n;i++) if(!ans[i]) ans[i] = cntr++; 
        for(int i=0;i<n;i++) cout << ans[i] << " ";
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
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/