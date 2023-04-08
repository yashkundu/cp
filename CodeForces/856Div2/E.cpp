/**
*   author: lazyhash(yashkundu)
*   created: 06 Mar, 2023 | 21:20:00
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



const int N = 2e5+100;
vector<int> cnt(N, 0);


ll h[2]={0}, b[2] = {(int)(rng()%(int)1e6+1e6), (int)(rng()%(int)1e6+1e6)};
ll mod[2] = {998244353, (int)1e9+7};
ll powB[2][N];


void precalc() {
    powB[0][0] = powB[1][0] = 1;
    for(int i=1;i<N;i++) {
        for(int j=0;j<2;j++) {
            powB[j][i] = (powB[j][i-1]*b[j])%mod[j];
        }
    }
}

vector<pair<ll, ll>> dp(N, {0LL, 0LL});
vector<pair<ll, ll>> vHash(N, {0LL, 0LL});
vector<int> g[N];

void dfs1(int v, int p) {
    dp[v] = {1, 1};
    for(int u: g[v]) {
        if(u==p) continue;
        dfs1(u, v);
        dp[v].first = (dp[v].first + dp[u].first*b[0])%mod[0];
        dp[v].second = (dp[v].second + dp[u].second*b[1])%mod[1];
    }
}


void dfs2(int v, int p) {
    if(v==0) vHash[v] = dp[0];
    else {
        ll h1 = (dp[v].first + (vHash[p].first - dp[v].first*b[0]%mod[0] + mod[0])*b[0])%mod[0];
        ll h2 = (dp[v].second + (vHash[p].second - dp[v].second*b[1]%mod[1] + mod[1])*b[1])%mod[1];
        vHash[v] = {h1, h2};
    }
    for(int u: g[v]) {
        if(u==p) continue;
        dfs2(u, v);
    }
}


void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n-1;i++) {
        int a;
        cin >> a;
        cnt[a]++;
    } 

    for(int i=0;i<n-1;i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    pair<ll, ll> cur_hash = {0, 0};

    for(int i=0;i<n;i++) {
        cur_hash.first = (cur_hash.first + powB[0][i]*cnt[i])%mod[0];
        cur_hash.second = (cur_hash.second + powB[1][i]*cnt[i])%mod[1];
    }

    vector<pair<ll, ll>> orig_hashes;

    for(int i=0;i<n;i++) {
        orig_hashes.emplace_back((cur_hash.first + powB[0][i])%mod[0], (cur_hash.second+powB[1][i])%mod[1]);
    }

    sort(orig_hashes.begin(), orig_hashes.end());

    dfs1(0, -1);
    dfs2(0, -1);

    vector<pair<pair<ll, ll>, int>> verHashes;
    vector<int> ans;

    for(int i=0;i<n;i++) {
        verHashes.emplace_back(vHash[i], i+1);
    }

    sort(verHashes.begin(), verHashes.end());


    // 2, 3, 5, 7, 14
    // 1, 3, 3, 3, 

    int j = 0;
    for(int i=0;i<n;i++) {
        while(j<n && orig_hashes[j]<verHashes[i].first) j++;
        if(j<n && orig_hashes[j]==verHashes[i].first) ans.push_back(verHashes[i].second);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int &x: ans) cout << x << " ";
    cout << "\n";



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    precalc();
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