/**
*    author:  lazyhash(yashkundu)
*    created: 22 Jul, 2024 | 20:00:20
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

const int MAXN = int(2e5)+10;

int n, k, p;
int s[MAXN];

vector<int> g[MAXN];
map<int, ll> mp[MAXN]; 


ll dfs(int v, int k) {
    if(mp[v].count(k)) return mp[v][k];
    ll res = 1LL*k*s[v];
    int sz = g[v].size();
    if(sz==0) {
        mp[v][k] = res;
        return res;
    }
    int del = k/sz;
    int extras = k%sz;
    vector<ll> vec;
    for(int u: g[v]) {
        ll a = dfs(u, del);
        ll b = 0;
        if(extras) b = dfs(u, del+1);
        res += a;
        vec.push_back(b-a);
    }

    sort(vec.rbegin(), vec.rend());

    for(int i=0;i<min(sz, extras);i++) res += vec[i];
    mp[v][k] = res;
    return res;
}



void solve() {
    cin >> n >> k;
    for(int i=0;i<n;i++) g[i].clear(), mp[i].clear();

    for(int i=1;i<n;i++) {
        cin >> p, p--; 
        g[p].push_back(i);
    }

    for(int i=0;i<n;i++) cin >> s[i];

    cout << dfs(0, k) << "\n";





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