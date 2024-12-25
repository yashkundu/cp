/**
*    author:  lazyhash(yashkundu)
*    created: 11 Sep, 2024 | 21:27:52
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n, m;
vector<vector<int>> a;


vector<vector<ll>> sum[2], freq[2];
 
void solve() {
    cin >> n >> m;
    a.resize(n);
    for(int i=0;i<n;i++) a[i].resize(m);


    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
            if(a[i][j]==3) a[i][j] = 0;
        }
    }

    int sz = n+m-1;

    for(int k=0;k<2;k++) {
        sum[k].resize(sz);
        for(int i=0;i<sz;i++) sum[k][i].resize(sz);
        for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) sum[k][i][j] = 0;
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