/**
*    author:  lazyhash(yashkundu)
*    created: 27 Jul, 2024 | 23:04:50
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

vector<pair<int, pair<int, int>>> g[MAXN];
 
int p, a, b;
int n;

int ans[MAXN];
vector<ll> vec;


void dfs(int v, ll cura) {
    if(v) {
        ans[v] = upper_bound(vec.begin(), vec.end(), cura) - vec.begin();
    }
    for(auto p: g[v]) {
        int u = p.first;
        ll x = p.second.first, y = p.second.second;
        if(!vec.empty()) y += vec.back();
        vec.push_back(y);
        dfs(u, cura + x);
        vec.pop_back();
    }
}


void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();


    for(int i=1;i<n;i++) {
        cin >> p >> a >> b, --p;
        g[p].push_back({i, {a, b}});
    }


    
    dfs(0, 0);

    for(int i=1;i<n;i++) cout << ans[i] << " ";
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