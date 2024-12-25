/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jun, 2024 | 20:26:08
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 105;
int a[MAXN][MAXN] = {0};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
 
void solve() {
    cin >> n >> m;

    for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) a[i][j] = 0;

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int mx = 0;
            for(int k=0;k<4;k++) {
                mx = max(mx, a[i+dx[k]][j+dy[k]]);
            }
            if(a[i][j]>mx) a[i][j] = mx;
        }
    }


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) cout << a[i][j] << " ";
        cout << "\n";
    }


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