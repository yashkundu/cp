/**
*    author:  lazyhash(yashkundu)
*    created: 07 Dec, 2024 | 01:01:29
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = (int)1e5+10;

int a[MAXN];

int n;
int el; 

void solve() {
    cin >> n;

    int mn = MAXN, mx = 0;

    for(int i=0;i<n;i++) {
        cin >> el;
        a[el]++;
        mn = min(mn, el);
        mx = max(mx, el);
    }


    ll ans = mn;
    a[mn]--;
    n--;

    int cur = mn;

    while(n>0) {
        int mngcd = MAXN;
        int mnel = -1;
        for(int i=1;i<=mx;i++) {
            if(!a[i]) continue;
            int curgcd = gcd(cur, i);
            if(curgcd<mngcd) {
                mngcd = curgcd;
                mnel = i;
            }
        }
        a[mnel]--;
        if(mngcd==cur) {
            ans += 1LL*n*cur;
            break;
        }
        ans += mngcd;
        cur = mngcd;
        n--;
    }

    cout << ans << "\n";





    for(int i=1;i<=mx;i++) a[i] = 0;



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