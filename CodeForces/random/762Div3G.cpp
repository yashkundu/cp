/**
*    author:  lazyhash(yashkundu)
*    created: 11 Oct, 2024 | 20:46:54
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

const int MAXN = (int)2e5+10;
const int inf = (int)1e9+10;

vector<int> g[MAXN];
bool vis[MAXN];

int n, k;
int x[MAXN], y[MAXN], tmr[MAXN];



map<int, vector<pair<int, int>>> vmp, hmp;


void build(map<int, vector<pair<int, int>>> &mp) {
    for(auto &p: mp) {
        sort(p.second.begin(), p.second.end());
        auto &v = p.second;
        for(int i=0;i<v.size()-1;i++) {
            if(v[i+1].first-v[i].first<=k) {
                g[v[i].second].push_back(v[i+1].second);
                g[v[i+1].second].push_back(v[i].second);
            }
        }
    }
}

vector<int> times;


int dfs(int v) {
    int x = tmr[v];
    vis[v] = 1;
    for(int u: g[v]) {
        if(vis[u]) continue;
        x = min(x, dfs(u));
    }
    return x;
}


 
void solve() {
    
    cin >> n >> k;
    for(int i=0;i<n;i++) g[i].clear();
    fill(vis, vis+n, 0);

    vmp.clear();
    hmp.clear();

    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i] >> tmr[i];

        if(!vmp.count(x[i])) vmp[x[i]] = vector<pair<int, int>>();
        vmp[x[i]].push_back({y[i], i});
        if(!hmp.count(y[i])) hmp[y[i]] = vector<pair<int, int>>();
        hmp[y[i]].push_back({x[i], i});
    }

    build(vmp);
    build(hmp);


    times.clear();
    for(int i=0;i<n;i++) {
        if(!vis[i]) times.push_back(dfs(i));
    }


    sort(times.begin(), times.end());
    int sz = times.size();

    int ans = sz-1;


    for(int i=0;i<times.size();i++) {
        int num = times[i];
        num += max(0, sz-i-1-(num+1));
        ans = min(ans, num);
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