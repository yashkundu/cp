/**
*    author:  lazyhash(yashkundu)
*    created: 11 Aug, 2024 | 18:34:00
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

vector<int> g[MAXN];
ll cnt[MAXN];

ll l[MAXN], r[MAXN];
int n;
int p;

int ops = 0;

void dfs(int v) {
    ll tot = 0;
    for(int u: g[v]) {
        dfs(u);
        tot += cnt[u];
    }
    if(tot<l[v]) {
        ops++;
        cnt[v] = r[v];
    } else {
        cnt[v] = min(r[v], tot);
    }
}
 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) g[i].clear();
    fill(cnt, cnt+n, 0);

    for(int i=1;i<n;i++) {
        cin >> p;
        p--;
        g[p].push_back(i);
    }


    for(int i=0;i<n;i++) cin >> l[i] >> r[i];

    ops = 0;

    dfs(0);

    cout << ops << "\n";


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