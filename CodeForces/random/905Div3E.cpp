/**
*    author:  lazyhash(yashkundu)
*    created: 05 Jul, 2024 | 13:32:22
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = int(1e5)+10;

ll a[MAXN], msb[MAXN];
ll shifts[MAXN];

ll ans = 0;

int n;


bool check(int i) {
    if(msb[i]+shifts[i]>msb[i-1]+shifts[i-1]) return false;
    return (a[i-1]<<(32-msb[i-1])) > (a[i]<<(32-msb[i]));
}

 
void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        msb[i] = 31 - __builtin_clz(a[i]);
        shifts[i] = 0;
    }

    int bitdel = 0;

    for(int i=1;i<=n;i++) {
        bitdel = max(0LL, msb[i-1] + shifts[i-1] - msb[i]);
        shifts[i] += bitdel;
        if(check(i)) shifts[i]++;
    }

    ans =0;
    ans = accumulate(shifts, shifts+n, 0LL);
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