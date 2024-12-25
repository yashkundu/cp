/**
*    author:  lazyhash(yashkundu)
*    created: 14 Jul, 2024 | 09:30:50
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

const int MAXN = 2005;
const int inf = int(1e9) + 10000;

struct FTree{
    vector<int> tree;
    int n;
    FTree(int n) {
        this->n = n;
        tree.resize(n+1);
        fill(tree.begin(), tree.end(), inf);
    }

    void update(int ind, int val) {
        for(;ind<=n;ind+=ind&-ind) tree[ind] = min(tree[ind], val);
    }

    int query(int ind) {
        int ans = inf;
        for(;ind>0;ind-=ind&-ind) ans = min(ans, tree[ind]);
        return ans;
    }
};

pair<int, int> nxt[MAXN];
int dp[MAXN][MAXN];


int n;
vector<pair<int, int>> v;
 

void minimize(int &x, int y) {
    x = min(x, y);
}

void solve() {
    cin >> n;
    v.resize(n);

    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    FTree ft(n);

    for(int i=n-1;i>=0;i--) {
        auto [l, r] = v[i];
        int ind = lower_bound(v.begin(), v.end(), make_pair(r+1, 0)) - v.begin();
        if(ind==i+1) nxt[i] = {inf, inf};
        else nxt[i] = {max(ft.query(ind), r), ind-1};
        ft.update(i+1, r);
    }


    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = inf;

    dp[0][0] = -1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            if(dp[i][j]==inf) continue;
            minimize(dp[i+1][j+1], dp[i][j]);
            if(v[i].first>dp[i][j] && nxt[i].first!=inf) {
                minimize(dp[nxt[i].second+1][j+nxt[i].second-i-1], nxt[i].first);
            }
        }
    }


    int ans = 0;
    for(int i=0;i<=n;i++) {
        if(dp[n][i]!=inf) {
            ans = i;
            break;
        }
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