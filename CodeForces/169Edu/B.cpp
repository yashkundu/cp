/**
*    author:  lazyhash(yashkundu)
*    created: 15 Aug, 2024 | 20:13:42
**/
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int l, r, L, R;

bool isInside(int x, int l, int r) {
    return x>=l && x<=r;
}

 
void solve() {
    cin >> l >> r >> L >> R;


    int cl = max(l, L), cr = min(r, R);

    if(cl>cr) {
        cout << 1 << "\n";
        return;
    }

    int ans = cr - cl;
    if(isInside(cl-1, l, r) || isInside(cl-1, L, R)) ans++;
    if(isInside(cr+1, l, r) || isInside(cr+1, L, R)) ans++;

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