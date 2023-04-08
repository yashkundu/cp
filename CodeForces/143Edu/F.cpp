/**
*   author: lazyhash(yashkundu)
*   created: 23 Feb, 2023 | 23:53:50
**/
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int N = 2e5+100;

int n;

vector<vector<int>> g; 
vector<int> dep(N, 0);
vector<bool> used(N, false);
vector<int> rem(N, 0);


// if all the vertices can perform the required steps
bool dfs(int v, int p=-1) {
    dep[v] = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        if(!dfs(u, v)) return false;
        if(!used[u]) dep[v] = max(dep[v], dep[u]+1);
    }
    if(rem[v]==0 || rem[v]<=dep[v]) return true;
    if(p==-1 || used[p]) return false;
    used[p] = true;
    rem[p] = rem[v] - 1;
    return true;
}
 
 
void solve() {
    cin >> n;
    g.assign(n, {});

    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> a(k);

    for(int &x: a) {
        cin >> x;
        x--;
    }

    int l = 0, r = n;
    while(r-l>1) {
        int mid = l + (r-l)/2;
        used.assign(n, false);
        dep.assign(n, 0);
        rem.assign(n, 0);

        for(int i=0;i<k;i++) {
            used[a[i]] = true;
            rem[a[i]] = mid/k + (i < mid%k);
        } 
        if(dfs(0)) l = mid;
        else r = mid;
    }

    cout << l << "\n";
    
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