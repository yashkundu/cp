/**
*   author: lazyhash(yashkundu)
*   created: 05 Mar, 2024 | 20:23:20
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+10;
int a[N], lft[N], rght[N];
bool vis[N];
 
void solve() {
    int n;
    cin >> n;
    
    fill(vis, vis+n, 0);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    int mex = 0;
    for(int i=0;i<n;i++) {
        vis[a[i]] = 1;
        while(mex<n && vis[mex]) mex++;
        lft[i] = mex;
    }

    fill(vis, vis+n, 0);

    mex = 0;
    for(int i=n-1;i>=0;i--) {
        vis[a[i]] = 1;
        while(mex<n && vis[mex]) mex++;
        rght[i] = mex;
    }

    for(int i=0;i<n-1;i++) {
        if(lft[i]==rght[i+1]) {
            cout << 2 << "\n";
            cout << 1 << " " << i+1 << "\n";
            cout << i+2 << " " << n << "\n";
            return;
        }
    }

    cout << "-1\n";


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