/**
*    author:  lazyhash(yashkundu)
*    created: 29 Jun, 2024 | 16:09:44
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5+10;

vector<int> g[MAXN];
int sz[MAXN];

int n;

void init(int v) {
    sz[v] = 1;
    for(int u: g[v]) {
        init(u);
        sz[v] += sz[u];
    }
}


int calc(int v, int k) {
    int tot = 0, mx = -1;
    for(int u: g[v]) {
        tot += sz[u];
        if(mx==-1 || sz[mx]<sz[u]) mx = u;
    }
    if(tot==0) return 0;
    if(sz[mx]-k<=tot-sz[mx])
        return (tot-k)/2;
    int x = tot-sz[mx];
    return x + calc(mx, max(0, k+x-1));
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=1;i<n;i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    init(0);

    cout << calc(0, 0) << "\n";




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