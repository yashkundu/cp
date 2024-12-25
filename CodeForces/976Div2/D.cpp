/**
*    author:  lazyhash(yashkundu)
*    created: 29 Sep, 2024 | 22:22:21
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


const int MAXN = (int)2e5+10;

vector<int> g[MAXN];
bool vis[MAXN];


vector<pair<int, int>> segs[11][11];


int n, m;

int a, d, k;

int l, r;
int cur;


void dfs(int v) {
    vis[v] = 1;
    for(int u: g[v]) {
        if(vis[u]) continue;
        dfs(u);
    }
}


 
void solve() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=10;i++) for(int j=1;j<=i;j++) segs[j][i].clear();
    fill(vis+1, vis+n+1, 0);



    for(int i=0;i<m;i++) {
        cin >> a >> d >> k;
        if(!k) continue;
        segs[(a-1)%d+1][d].push_back({a, a+k*d});
    }

    for(int i=1;i<=10;i++) for(int j=1;j<=i;j++) sort(segs[j][i].begin(), segs[j][i].end());




    for(int i=1;i<=10;i++) for(int j=1;j<=i;j++) {
        cur = 0;
        for(auto p: segs[j][i]) {
            l = p.first; r = p.second;
            cur = max(l, cur);
            while(cur<r) {
                g[cur].push_back(cur+i);
                g[cur+i].push_back(cur);
                cur = cur+i;
            }
        }
    }


    int ans = 0;



    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            ans++;
            dfs(i);
        }
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