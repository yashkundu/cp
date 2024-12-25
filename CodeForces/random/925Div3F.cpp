/**
*    author:  lazyhash(yashkundu)
*    created: 24 Jun, 2024 | 12:27:42
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
int col[MAXN];

int n, k;
vector<int> a;

bool isCyclic(int v) {
    if(col[v]) return false;
    col[v] = 1;
    for(int u: g[v]) {
        if(!col[u] && isCyclic(u)) return true; 
        else if(col[u]==1) return true;
    }
    col[v] = 2;
    return false;
}

 
void solve() {
    cin >> n >> k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++) col[i] = 0;

    a.resize(n);

    for(int j=0;j<k;j++) {
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=1;i<n-1;i++) g[a[i]].push_back(a[i+1]);
    }

    for(int i=1;i<=n;i++) {
        if(isCyclic(i)) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";






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