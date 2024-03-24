/**
*   author: lazyhash(yashkundu)
*   created: 14 Mar, 2024 | 23:20:12
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5;

vector<pair<int, int>> g[N];
int valV[N], valE[N];

int p;
int n;

int cntr;


void dfs(int v, int p) {
    for(auto [edge, u]: g[v]) {
        if(u==p) continue;
        if(valV[v]>=n) {
            valE[edge] = cntr + n;
            valV[u] = cntr;
        } else {
            valE[edge] = cntr;
            valV[u] = cntr + n;
        }
        cntr++;
        dfs(u, v);
    }
}

// dp[i] = max(dp[j] + (i-j)) for all j < i
// can be generalized
// dp[i] -> (dp[j] + (i-j))
// max(dp[j]-j) for all j < i
// ftre
 
void solve() {
    cin >> p;
    // n = 2^p

    n = 1<<p;


    for(int i=0;i<n;i++) g[i].clear();
    cntr = 1;

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(i, v);
        g[v].emplace_back(i, u);
    }

    valV[0] = n;
    dfs(0, -1);

    cout << 1 << "\n";
    for(int i=0;i<n;i++) cout << valV[i] << " ";
    cout << "\n";
    for(int i=0;i<n-1;i++) cout << valE[i] << " ";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/