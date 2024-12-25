/**
*    author:  lazyhash(yashkundu)
*    created: 15 Jul, 2024 | 17:28:19
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(2e5)+10;

vector<pair<int, int>> g[MAXN];

int n;
int u, v;

vector<int> ans;
bool good = true;
int cnt[3];

int dfs(int v, int e=0, int p=-1) {
    int num = 1;
    int cnt[3];
    cnt[1] = cnt[2] = 0;
    for(auto [u, edge]: g[v]) {
        if(u==p) continue;
        int x = dfs(u, edge, v);
        if(x) {
            if(x>2) {
                good = false;
                return 0;
            }
            cnt[x]++;
            num += x;
        }
    }
    if(cnt[2]>1 || cnt[1]>2 || (cnt[1]&cnt[2])) {
        good = false;
        return 0;
    }
    if(num==3) {
        if(e) ans.push_back(e);
        return 0;
    } 
    return num;
}


 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();

    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, i+1});
        g[v].push_back({u, i+1});
    }


    ans.clear();
    good = true;
    if(dfs(0) || !good) {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << "\n";
    for(int e: ans) cout << e << " ";
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