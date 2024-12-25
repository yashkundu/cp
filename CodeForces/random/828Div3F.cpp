/**
*    author:  lazyhash(yashkundu)
*    created: 23 Jul, 2024 | 00:17:36
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

int n;
int p[MAXN], inds[MAXN];

ll ans = 0;
int mxlen;
int del;
int l, r;
 
void solve() {
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> p[i];
        inds[p[i]] = i;
    }
    inds[n] = n;

    l = inds[0];
    r = inds[0];
    
    
    ans = 1;
    for(int x=0;x<n-1;) {
        mxlen = 2*(x+1);
        if(inds[x+1]<l) {
            for(int i=l;i>inds[x+1];i--) {
                del = mxlen - (r-i+1);
                if(del<0) break;
                ans += min(del+1, n-r);
            }
        } else {
            for(int i=r;i<inds[x+1];i++) {
                del = mxlen - (i-l+1);
                if(del<0) break;
                ans += min(del+1, l+1);
            }
        }


        l = min(l, inds[x+1]);
        r = max(r, inds[x+1]);
        x++;
        while(inds[x+1]>=l && inds[x+1]<=r) x++;
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