/**
*    author:  lazyhash(yashkundu)
*    created: 17 Jul, 2024 | 13:31:48
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(3e5) + 10;
const ll inf = ll(1e18) + 10000;

int n, k;
int a[MAXN];

ll cold[MAXN], hot[MAXN];
ll psum[MAXN];
ll dp[MAXN];
int nxt[MAXN];

vector<int> pos[MAXN];


vector<int> v;

ll ans = 0;

void minimize(ll &x, ll y) {
    x = min(x, y);
}

 
void solve() {
    cin >> n >> k;

    for(int i=1;i<=k;i++) pos[i].clear();

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=1;i<=k;i++) cin >> cold[i];
    for(int i=1;i<=k;i++) cin >> hot[i];

    v.clear();
    ans = 0;

    for(int i=0;i<n;i++) {
        if(!v.empty() && a[i]==v.back()) ans += hot[a[i]];
        else v.push_back(a[i]);
    }

    n = int(v.size());

    for(int i=n-1;i>=0;i--) {
        if(pos[v[i]].empty()) nxt[i] = n;
        else nxt[i] = pos[v[i]].back();
        pos[v[i]].push_back(i);
    }


    psum[0] = cold[v[0]];
    for(int i=1;i<n;i++) {
        psum[i] = psum[i-1] + cold[v[i]];
    }

    for(int i=0;i<n;i++) dp[i] = inf;
    dp[0] = psum[0];



    for(int i=0;i<n-1;i++) {
        minimize(dp[i+1], dp[i]+cold[v[i+1]]);
        if(nxt[i]!=n) minimize(dp[nxt[i]], dp[i] + (psum[nxt[i]-1] - psum[i]) + hot[v[i]]);
        if(i>0 && nxt[i-1]!=n) minimize(dp[nxt[i-1]], dp[i] + (psum[nxt[i-1]-1] - psum[i]) + hot[v[i-1]]); 
    }

    ans += dp[n-1];

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