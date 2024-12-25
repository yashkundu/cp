/**
*    author:  lazyhash(yashkundu)
*    created: 18 Jul, 2024 | 20:06:51
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
 
void solve() {
    cin >> n >> m;

    a.resize(n);
    for(int i=0;i<n;i++) a[i].resize(m);

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];

    if(n*m==1) {
        cout << "-1\n";
        return;
    }

    if(m>1) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) cout << a[i][(j+1)%m] << " ";
            cout << "\n";
        }
    }
    else {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) cout << a[(i+1)%n][j] << " ";
            cout << "\n";
        }
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