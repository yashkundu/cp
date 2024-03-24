/**
*   author: lazyhash(yashkundu)
*   created: 20 Mar, 2024 | 10:21:33
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int M = 18;
vector<int> g[N];
bool col[N];
int ans[N];


void dfs(int v, int p) {
    for(int u: g[v]) {
        if(u==p) continue;
        col[u] = !col[v];
        dfs(u, v);
    }
}

 
void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    col[0] = 1;
    dfs(0, -1);

    int cnt0 = 0, cnt1 = 0;
    for(int i=0;i<n;i++) if(col[i]) cnt1++; else cnt0++;


    bool goodCol = (cnt1<=cnt0);
    int minCnt = min(cnt0, cnt1);

    vector<int> goodVals, badVals;

    int x = 1;
    while(x<=n) {
        bool isLast = (2*x-1>n);
        for(int j=x;j<min(2*x, n+1);j++) {
            if(isLast || !(minCnt&x)) badVals.push_back(j);
            else goodVals.push_back(j); 
        }
        x *= 2;
    }

    for(int i=0;i<n;i++) {
        if(col[i]==goodCol) {
            ans[i] = goodVals.back();
            goodVals.pop_back();
        } else {
            ans[i] = badVals.back();
            badVals.pop_back();
        }
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
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