/**
*    author:  lazyhash(yashkundu)
*    created: 24 Dec, 2024 | 00:18:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 205;

const ll inf = (ll)1e18+10;

int n, m;
ll k;

vector<vector<ll>> dp1;
vector<vector<vector<ll>>> dp2;

ll a[MAXN][MAXN];

void minimize(ll &x, ll y) {
    x = min(x, y);
}
 
void solve() {
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }

    dp1.resize(n);
    for(int i=0;i<n;i++) dp1[i].resize(m);

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp1[i][j] = inf;

    dp2.resize(n);
    for(int i=0;i<n;i++) dp2[i].resize(m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dp2[i][j].resize(m);

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int shft=0;shft<m;shft++) dp2[i][j][shft] = inf;



    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int shft=0;shft<m;shft++) {
                ll cur = a[i][(j+shft)%m];
                if(i==0 && j==0) {
                    minimize(dp2[i][j][shft], cur + k*shft);
                } else {
                    if(i>0) minimize(dp2[i][j][shft], dp1[i-1][j] + k*shft + cur);
                    if(j>0) minimize(dp2[i][j][shft], dp2[i][j-1][shft] + cur);
                }
                minimize(dp1[i][j], dp2[i][j][shft]);
            }
        }
    }

    cout << dp1[n-1][m-1] << "\n";






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