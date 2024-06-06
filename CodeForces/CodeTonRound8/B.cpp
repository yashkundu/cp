/**
*   author: lazyhash(yashkundu)
*   created: 30 Mar, 2024 | 20:32:23
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;
bool vis[N];
 
void solve() {
    int n;
    cin >> n;

    fill(vis, vis+n, 0);

    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> p(n);


    if(a[0]==1) p[0] = 0;
    else p[0] = -a[0];

    vis[p[0]] = 1;

    int mex = (p[0]==0?1:0);

    for(int i=1;i<n;i++) {
        // take cur mex
        // mex - x = a
        int x = mex - a[i];
        if(x>=0 && x<n && !vis[x] && x!=mex) {
            p[i] = x;
            vis[p[i]] = 1;
            continue;
        }

        // take next element as mex
        p[i] = mex;
        vis[p[i]] = 1;
        while(mex<n && vis[mex]) mex++;
        assert(mex-p[i]==a[i]);
    }

    for(int i=0;i<n;i++) cout << p[i] << " ";
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
* logic OVER intuition
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* - BenQ
*/