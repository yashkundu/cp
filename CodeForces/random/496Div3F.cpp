/**
*   author: lazyhash(yashkundu)
*   created: 06 Apr, 2024 | 08:11:48
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
vector<int> g[N];
vector<int> par[N];
int dep[N];
map<pair<int, int>, int> mp;

int n, m, k;


void calc(vector<bool> &e, int v, vector<vector<bool>> &ans) {
    if(v==n) {
        ans.push_back(e);
        return;
    }
    for(int u: par[v]) {
        if(ans.size()==k) return;
        int a = u, b = v;
        int ind = mp[{min(a, b), max(a, b)}];
        e[ind] = 1;
        calc(e, v+1, ans);
        e[ind] = 0;
    }
}

 
void solve() {
    cin >> n >> m >> k;

    for(int i=0;i<n;i++) dep[i] = -1;
    for(int i=0;i<n;i++) g[i].clear(), par[i].clear();

    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        mp[{min(a, b), max(a, b)}] = i;
    }

    dep[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u: g[v]) {
            if(dep[u]==-1) {
                q.push(u);
                dep[u] = 1 + dep[v];
                par[u].push_back(v);;
            } else if(dep[u]==1+dep[v]) {
                par[u].push_back(v);
            }
        }
    }

    vector<bool> e(m, 0);
    vector<vector<bool>> ans;

    calc(e, 1, ans);

    cout << ans.size() << "\n";

    for(vector<bool> &v : ans) {
        for(bool x: v) {
            cout << (x?1:0);
        }
        cout << "\n";
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